FROM python:2.7

RUN apt-get update

RUN pip install bigquery-python && \
    pip install google-cloud && \
    pip install Flask && \
    pip install mysql-connector==2.1.4 && \
    pip install flask-cors --upgrade

WORKDIR /script

COPY ./ /script

CMD [ "python", "./server.py" ]
