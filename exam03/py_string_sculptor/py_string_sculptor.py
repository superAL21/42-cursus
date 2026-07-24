def string_sculptor(text: str) -> str:
	result = ""
	turn_lower = True

	for c in text:
		if c == " ":
			result += " "
			turn_lower = True

		elif c.isalpha():
			if turn_lower:
				result += c.lower()
			else:
				result += c.upper()

			turn_lower = not turn_lower

		else:
			result += c

	return result	