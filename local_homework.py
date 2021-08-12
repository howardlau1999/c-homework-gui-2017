import os, json

homework_dir = "homework"
compilable_dir = "compilable"

def saveSingleHomework(hw, hwid):
    f = open("%s/%s.txt" % (homework_dir, hwid), "w")
    answer = hw.get('answer')
    answer = answer.replace("\x0d", "")
    f.write(answer)
    f.close()
    saveCompilableCode(hw, hwid)

def saveHomeworkData(hwData, hwid = None):
    if not os.path.exists(homework_dir):
        os.mkdir(homework_dir)
    if hwid is not None:
        saveSingleHomework(hwData[hwid], hwid)
        return
    for id in hwData:
        answer = hwData[id].get('answer')
        if answer is None or answer == '':
            continue
        f = open("%s/%s.txt" % (homework_dir, id), "w")
        answer = answer.replace("\x0d", "")
        f.write(answer)
        f.close()
        saveCompilableCode(hwData[id], id)

def saveCompilableCode(hw, hwid):
    if not os.path.exists(compilable_dir):
        os.mkdir(compilable_dir)

    ext = {"g++" : "cpp", "gcc" : "c"}

    f = open("%s/%s.%s" % (compilable_dir, hwid, ext[hw['compiler']]), "w")
    f.write(hw['main'].replace(r'#include "source"', hw['answer'].replace("\x0d", "")))
    f.close()

def loadSingleHomework(hwid):
    homework_fn = "%s/%s.txt" % (homework_dir, hwid)
    if not os.path.exists(homework_dir):
        os.mkdir(homework_dir)
    if not os.path.exists(homework_fn):
        return -1;
    f = open(homework_fn, "r")
    homework = f.read()
    homework = homework.replace("\x0d", "")
    f.close()
    return homework