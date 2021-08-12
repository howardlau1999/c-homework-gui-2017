#! python3
# -*- coding: utf-8 -*-
import os, hashlib, threading, json
from urllib import request


class Updater(object):
	"""docstring for Updater"""
	def __init__(self):
		super(Updater, self).__init__()
		self.base_url = "http://cupdate.howardlau.me/"
		self.md5_url = "http://cupdate.howardlau.me/publish/md5list.json"
		self.file_url = ""
		self.will_update = []
		self.update_tmp_dir = "update/"
		

	def getMD5(self, fn):
		f = open(fn, "rb")
		content = f.read()
		f.close()
		return hashlib.md5(content).hexdigest()

	def compareLocalWithRemote(self, remoteMD5list):
		self.will_update.clear()
		for fn in remoteMD5list:
			if not os.path.exists(fn):
				self.will_update.append(fn)
				continue
			if self.getMD5(fn) != remoteMD5list[fn]:
				self.will_update.append(fn)

	def downloadFile(self, fn, retry = 5):
		if not os.path.exists(self.update_tmp_dir):
			os.mkdir(self.update_tmp_dir)

		if retry == 0:
			raise Exception("Download File Failed!")
		try:
			req = request.urlopen(self.file_url + fn)
			content = req.read()
			f = open(self.update_tmp_dir + fn, "wb")
			f.write(content)
			f.close()
		except:
			self.downloadFile(fn, retry - 1)
		
	def parseRemoteMD5(self, url):
		req = request.urlopen(url)
		md5list = json.loads(req.read().decode())
		return md5list

	def replaceFiles(self):
		for fn in self.will_update:
			if os.path.exists(fn):
				os.remove(fn)
			os.rename(self.update_tmp_dir + fn, fn)
		if os.path.exists(self.update_tmp_dir):
			os.rmdir(self.update_tmp_dir)

	def update(self):
		md5list = self.parseRemoteMD5(self.md5_url)
		if md5list == {}:
			return
		self.file_url = self.base_url + md5list['base_path']
		del md5list['base_path']
		self.compareLocalWithRemote(md5list)
		for fn in self.will_update:
			self.downloadFile(fn)
		self.replaceFiles()
		return len(self.will_update)

if __name__ == '__main__':
	u = Updater()
	a = input("即将开始更新，按回车继续。")
	input("更新了 %d 个文件。按回车退出。" % u.update())

	

	