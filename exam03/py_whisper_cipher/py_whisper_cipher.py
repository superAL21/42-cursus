def whisper_cipher(text: str, shift: int) -> str:
	result = ""

	for c in text:
		if c.isalpha():
			base = ord('A') if c.isupper() else ord('a')
			new = (ord(c) - base + shift) % 26
			result += chr(new + base)

		else:
			result += c

	return result