import os
import json
import requests
import base64
from bs4 import BeautifulSoup

# Definimos la función que convierte la imagen en base64
def get_image_base64(query):
    # Realizamos una solicitud HTTP a Google Imágenes
    url = f"https://www.google.com/search?q={query}&tbm=isch"
    headers = {'User-Agent': 'Mozilla/5.0'}
    response = requests.get(url, headers=headers)

    # Extraemos la URL de la imagen en el primer resultado de búsqueda
    soup = BeautifulSoup(response.text, 'html.parser')
    img_url = soup.find_all('img')[1]['src']

    # Descargamos la imagen y la convertimos a base64
    img_content = requests.get(img_url).content
    img_base64 = base64.b64encode(img_content).decode()

    return img_base64

# Ejemplo de uso
query = input("Texto: ")
img_base64 = get_image_base64(query)

# Verificamos si el archivo existe
if os.path.exists("images.json"):
    # Si el archivo existe, cargamos los datos existentes en un objeto de Python
    with open("images.json", "r") as f:
        data = json.load(f)
else:
    # Si el archivo no existe, creamos un diccionario vacío
    data = {}

# Agregamos los nuevos datos al objeto de Python
data[query] = img_base64

# Convertimos el objeto de Python actualizado a una cadena JSON
json_data = json.dumps(data)

# Escribimos la cadena JSON actualizada en el archivo
with open("images.json", "w") as f:
    f.write(json_data)