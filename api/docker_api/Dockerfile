FROM python:2.7

RUN apt-get update

RUN pip install paho-mqtt && \
    pip install mysql-connector==2.1.4 

WORKDIR /script

COPY ./ /script

CMD [ "python", "./api_V1.py" ]
