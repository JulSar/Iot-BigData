from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'GPS'

if __name__ == '__main__':
    app.run(debug=False, threaded=True, port=5000, host='0.0.0.0')
