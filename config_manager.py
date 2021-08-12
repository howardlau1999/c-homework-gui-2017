import os, json

config_fn = "config.json"

def loadConfig():
    if not os.path.isfile(config_fn):
        return None
    else:
        try:
            f = open(config_fn, "r")
            config = json.loads(f.read())
            return config
        except:
            return None
        finally:
            f.close()

def saveConfig(config):
    f = open(config_fn, "w")
    f.write(json.dumps(config) + '\n')
    f.close()