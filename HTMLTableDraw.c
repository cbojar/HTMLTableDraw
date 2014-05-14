/*******************************************************************************
 * HTMLTableDraw.c
 * Usage: HTMLTableDraw [iterations]
 * where iterations is the number of pixels along the side of the square
 * (total pixels = iterations x iterations)
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int iterations = 20; // Default of 20 iterations

int main(int argc, char *argv[]) {
	int i, j; // Counters
	clock_t start = clock(), end; // Timers for C code

	if(argc > 1) { // Check for argument
		iterations = atoi(argv[1]); // Parse as int
	}

	printf("<!DOCTYPE html>\n<html><head>"); // Print out boilerplate
	printf("<title>%dx%d</title>", iterations, iterations); // Set page title
	printf("<script>var start=new Date();</script>"); // Script to start JS timer
	printf("<style>table.draw td{width: 1px; height: 1px;}</style>"); // Styles
	printf("</head><body>"); // More boilerplate
	puts("<table class=\"draw\" cellpadding=\"0\" cellspacing=\"0\">"); // Start the table
	for(i = 0; i < iterations; i++) { // Rows
		printf("<tr>");
		for( j = 0; j < iterations; j++ ) { // Columns
			printf(
				"<td style=\"background-color: #%.2X%.4X;\"></td>",
				((i * j * 35) % 0xFF ) / 2, // Something calculated for red
				(i * j * 35) % 0xFFFF // Something calculated for blue and green
			);
		}
		puts("</tr>");
	}
	puts("</table>"); // Close table

	end = clock();
	printf("<br />\nCreate time: %f seconds.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	printf("<p>Process Time: <script>var end=new Date(); document.write(((end.getTime() - start.getTime()) / 1000));</script> s<br />");
	printf("Bytes per pixel: %lu.<br />", strlen("<td style=\"background-color: #FFFFFF;\"></td>") * sizeof(char));
	printf("<a href=\"http://github.com/cbojar/HTMLTableDraw\">Make your own!</a>");
	printf("</body></html>");

	return 0;
}
