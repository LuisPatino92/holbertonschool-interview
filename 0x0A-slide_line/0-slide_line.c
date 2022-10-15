#include <stddef.h>
#include "slide_line.h"


/**
 * mix - Merging m
 *
 * @line: Line Representation
 * @m: Direction identifier
 * @i: cnt line
 * @start: First val
 * @cnt: mixable value
 * @cnt_index: id
 * @blank: Blank values
 *
 * Return: No Return
 */
void mix(int *line, int m, int i, int start,
	int *cnt, int *cnt_index, int *blank) {
	if (line[i] == 0)
		*blank += 1;

	if (i == start && line[i] != 0)	{
		*cnt = line[i];
		*cnt_index = i;
	}

	if (line[i] != 0 && line[i] == *cnt && i != start) {
		line[*cnt_index] += line[i];
		line[i] = 0;
		*cnt = 0;
		*blank += 1;
	}

	if (line[i] != 0 && *cnt != line[i] && i != start) {
		line[i - (*blank * m)] = line[i];
		*cnt = line[i];
		*cnt_index = i - (*blank * m);
		if (*blank)
			line[i] = 0;
	}
}


/**
 * slide_line - main function
 *
 * @line: Line model.
 * @size: Line Size.
 * @direction: Direction.
 *
 * Return: O wheter fails 1 otherwise
 */
int slide_line(int *line, size_t size, int direction) {
	int m, cnt, cnt_index, blank, start, i;
	int sizeX = (int) size;

	if (!line || (direction != 0 && direction != 1))
		return (0);

	blank = 0;
	cnt = 0;

	if (direction == 0)
		m = 1;
	else
		m = -1;

	if (direction != 0) {
		for (i = start = cnt_index = sizeX - 1; i >= 0; i--) {
			mix(line, m, i, start,
				&cnt, &cnt_index, &blank);
		}
	} else {
		for (i = start = cnt_index =  0; i < sizeX; i++) {
			mix(line, m, i, start,
				&cnt, &cnt_index, &blank);
		}
	}

	return (1);
}
