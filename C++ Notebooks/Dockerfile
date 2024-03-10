FROM continuumio/miniconda3

WORKDIR /app

COPY . /app

RUN conda install jupyter xeus-cling -c conda-forge -y

EXPOSE 8888

CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--port=8888", "--no-browser", "--allow-root"]
