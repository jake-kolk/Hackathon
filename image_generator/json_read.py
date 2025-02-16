import json
import os
import base64
from PIL import Image
from io import BytesIO

f = open("generated_image.json", "r")
content = f.read()

response_json = json.loads(content)
encoded_str = response_json["result"]["image"]
image_bytes = base64.b64decode(encoded_str)
image_stream = BytesIO(image_bytes)
image = Image.open(image_stream)
# decoded_image = decoded_image.decode('utf-8')

filename = "generated_image.png"
image.save(filename)
print(f"Image saved as {filename}")