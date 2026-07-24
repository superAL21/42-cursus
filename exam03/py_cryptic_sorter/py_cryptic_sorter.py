def cryptic_sorter(strings: list[str]) -> list[str]:
	new_list = list(strings)
	n = len(new_list)
	def count_vocals(string: str) -> int:
		vocals = "aeiou"
		count = 0
		for c in string:
			if c in vocals:
				count += 1
		return count

	def get_data(string: str) -> tuple:
		long = len(string)
		alpha = string.lower()
		vocals = count_vocals(string)
		return(long, alpha, vocals, string)

	for i in range(n):
		for j in range(n - i - 1):
			current = get_data(new_list[j])
			next = get_data(new_list[j + 1])
			if current > next:
				new_list[j], new_list[j + 1] = new_list[j + 1], new_list[j]

	return new_list
