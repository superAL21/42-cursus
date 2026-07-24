def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
	new_list = []
	for group in matrix:
		lol = group[::-1]
		new_list.append(lol)

	return new_list
