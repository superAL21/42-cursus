def pattern_tracker(text: str) -> int:
	if not text or len(text) < 2:
		return 0

	count = 0

	for i in range(len(text) - 1):
		current = text[i]
		next = text[i + 1]

		if current.isdigit() and next.isdigit():
			if int(next) - int(current) == 1:
				count += 1

	return count