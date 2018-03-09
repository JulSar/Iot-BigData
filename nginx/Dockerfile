FROM nginx:alpine

MAINTAINER Pascal LUTTGENS<pascal.luttgens@hotmail.fr>

RUN rm -rf /etc/nginx/conf.d
COPY nginx.conf /etc/nginx
COPY front /etc/nginx/html/front/

# Define mountable directories.
VOLUME ["/var/log/nginx"]
VOLUME ["/etc/nginx/html/front/"]

# Define working directory.
WORKDIR /etc/nginx

# RUN filewatcher "nginx.conf" "nginx -s reload" &

EXPOSE 80

# Define default command.
CMD ["nginx"]
