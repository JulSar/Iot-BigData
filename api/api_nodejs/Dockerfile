FROM node:alpine

COPY package.json .
RUN npm i
COPY index.js .

CMD ["npm", "run", "start"]