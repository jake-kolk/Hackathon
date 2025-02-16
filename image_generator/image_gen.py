import requests
import json
import base64
import os
from PIL import Image
from io import BytesIO
import sys
from datetime import datetime

ACCOUNT_ID = "5731b7c6d2eb34288a0ba7742c369b4d"

API_TOKEN = "m_CmP-5DiYFsmxfNY38G5nFqEtpXRI0NI6gg8Jyw"

API_BASE_URL = "https://api.cloudflare.com/client/v4/accounts/" + ACCOUNT_ID + "/ai/run/@cf/black-forest-labs/flux-1-schnell"
MODEL = "@cf/black-forest-labs/flux-1-schnell"
# headers = {"Authorization": "Bearer " + API_TOKEN}

# Set up headers for authentication
headers = {
    "Authorization": f"Bearer {API_TOKEN}",
    "Content-Type": "application/json"
}

# Function to generate image from prompt
def generate_image(filename, prompt):
    payload = {
        "prompt": prompt,
        "num_images": 1,  # Number of images to generate
        "size": "1024x1024"  # Image size, can be modified based on Cloudflare's supported sizes
    }

    response = requests.post(API_BASE_URL, json=payload, headers=headers)
    # print("response: ", response.content)
    if response.status_code == 200:
        response_json = json.loads(response.content)
        encoded_str = response_json["result"]["image"]
        image_bytes = base64.b64decode(encoded_str)
        image_stream = BytesIO(image_bytes)
        image = Image.open(image_stream)
        image.save(filename)
        print(f"Image saved as {filename}")

    else:
        print(f"Error generating image: {response.status_code} - {response.text}")
        return None

# Main function
def main(filename, prompt):
    # prompt = input("Enter a prompt to generate an image: ")
    generate_image(filename, prompt)


if __name__ == "__main__":
    filename = sys.argv[1]
    prompt = sys.argv[2]
    main(filename, prompt)
