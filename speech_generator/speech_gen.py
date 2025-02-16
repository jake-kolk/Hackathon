import torch
from TTS.api import TTS
import time
import sys

def main(filename, prompt):
    start_time = time.time()

    device = "cuda" if torch.cuda.is_available() else "mps"

    # Load model (supports multiple languages)

    tts = TTS("tts_models/en/ljspeech/vits").to("mps")

    tts.tts_to_file(text=prompt, file_path=filename)

    end_time = time.time()

    elapsed_time = end_time - start_time

    print(f"Rum time: {elapsed_time: .4f}")

if __name__ == "__main__":
    filename = sys.argv[1]
    text = sys.argv[2]

    main(filename, text)
