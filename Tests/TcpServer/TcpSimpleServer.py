import zmq
import time
from datetime import datetime

##########LOGGER##########
class Logger:
    def __init__(self, filepath):
        self.logs = []
        self.log_file = open(filepath, 'w', encoding="utf-8")

    def __del__(self):
        self.flush()

    def flush(self):
        for log_message in self.logs:
            self.log_file.write(log_message + "\n") # еще дату

        self.logs.clear()

    def log(self, msg):
        log_message = self.form_log_message(msg)
        self.logs.append(log_message)

        self.flush()

    def form_log_message(self, msg):
        current_tine = msg + " " + datetime.now().strftime("%m/%d/%Y, %H:%M:%S")
        return ( msg + current_tine)

##########TCP_SERVER##########
class TcpSimpleServer:
    def __init__(self, context, logger):
        self.connections = []
        self.context = context
        self.socket = context.socket(zmq.REP)
        self.logger = logger
        
    def __del__(self):
        self.logger("Server closed")

    def bind(self, ip, port):
        self.socket.bind('tcp://127.0.0.1:5555');

    def start(self):
        print("Start server")
        logger.log("Start server")

        self.MainLoop()

    def MainLoop(self):
        while True:
            message = self.socket.recv()

            print("New message!")    
            self.logger.log("New message!")
            time.sleep(1)
            self.socket.send(b"Hello from server")

#Можно using

context = zmq.Context()
logger = Logger("Log.txt")

tcpServer = TcpSimpleServer(context, logger)

tcpServer.bind("127.0.0.1", 5555)
tcpServer.start()