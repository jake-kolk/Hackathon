import torch
from TTS.api import TTS
import time
import sys

def main(filename, prompt):
    start_time = time.time()

    device = "cuda" if torch.cuda.is_available() else "mps"

    # Load model (supports multiple languages)
    # tts = TTS(model_name="tts_models/en/ljspeech/fast_pitch").to("cuda" if torch.cuda.is_available() else "mps")

    tts = TTS("tts_models/en/ljspeech/vits").to("mps")
    # wav = tts.tts("This is a test! This is also a test!!", speaker=tts.speakers[0], language=tts.languages[0])

    tts.tts_to_file(text=story, file_path="output.wav")

    end_time = time.time()

    elapsed_time = end_time - start_time

    print(f"Rum time: {elapsed_time: .4f}")

if __name__ == "__main__":
    # filename = sys.argv[1]
    # text = sys.argv[2]
    story = """Milo and the Magic Paintbrush
Milo the mouse loved to paint. Every day, he would dip his tiny brush into colorful paints and create beautiful pictures on leaves, stones, and even tree bark. But one day, as he was searching for a new canvas, he found something unusual—a golden paintbrush lying in the grass!

Curious, he picked it up and gave it a little stroke on the ground. To his surprise, a bright red apple appeared—real and shiny!

"It's a magic paintbrush!" Milo gasped.

Excited, he painted a loaf of bread, and—poof!—it turned real. He painted a warm scarf, and it wrapped around him like a hug.

Milo wanted to share his discovery, so he ran to the village and painted toys for the little mice, fresh food for the elders, and colorful flowers to brighten up the streets. Everyone cheered for Milo’s magical gift!

But then, he saw Timmy, a tiny mouse shivering in the cold. Milo smiled and painted a cozy little house for him.

"Thank you, Milo!" Timmy said, hugging him.

That night, Milo looked at his magic brush and knew he had found something even more special than magic—he had found the joy of helping others.

And from that day on, Milo used his brush not just for fun, but to make the world a brighter place.

The End."""
    
    main("output.wav", story)
