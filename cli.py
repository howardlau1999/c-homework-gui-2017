# -*- coding: utf-8 -*-

import os, sys, argparse, json, time, socket
import imp

# host_ip = '222.200.177.80'
host_ip = '127.0.0.1'
host_port = 8000

def receive_line(connect, timeout=1):
	connect.settimeout(timeout)
	data = []
	while True:
		d = bytes.decode(connect.recv(4096))
		if d is None:
			time.sleep(0.1)
		else:
			data.append(d)
			if '\n' in d:
				break;
	return ''.join(data)

def send_request(request):
	# host_ip = socket.gethostbyname(host_name) # socket.gaierror: could not resolve host name
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # socket.error: fail to create socket
	s.connect((host_ip, host_port))
	message = json.dumps(request) + '\n'
	s.sendall(str.encode(message)) # socket.error: fail to send
	reply = receive_line(s, timeout=5)
	return json.loads(reply)

def load_file(filename):
	if not os.path.isfile(filename):
		print('文件不存在 "%s"' % filename)
		return None
	with open(filename) as f:
		f.read()
		f.close()

def save_file(filename, text):
	with open(filename, 'w') as f:
		f.write(text)
		f.close()

def sort_problem_ids(problem_ids):
	def get_id(problem_id):
		problem_id = problem_id.split('.')
		return 1000 * int(problem_id[0]) + int(problem_id[1])
	problem_ids.sort(key = lambda id : get_id(id))


def homework_info(args):
	print('\n正在获取作业信息...')
	request = args
	request['request'] = 'homework_info'
	reply = send_request(request)
	if 'reply' in reply:
		if reply['reply'].startswith('ERROR:'):
			return {"error": reply['reply']}
		else:
			return reply
	else:
		return {"error": "发生错误"}

def save_homework(args):
	request = args
	request['request'] = 'save_homework'
	print('\n正在保存作业...')
	reply = send_request(request)
	print(reply['reply'])
	return reply['reply']

def download(args):
	request = args
	request['request'] = 'download'
	reply = send_request(request)
	if reply['reply'] == 'OK':
		save_file(reply['filename'], reply['file_content'])
		return {"filename" : reply['filename']}
	else:
		return {"error" : reply['reply']}