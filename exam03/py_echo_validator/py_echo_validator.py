def echo_validator(text: str) -> bool:
	reverse = ""
	if not text:
		return False

	for c in text:
		if c.isalpha():
			reverse += c.lower()
	vuelta = reverse[::-1]
	return reverse == vuelta

