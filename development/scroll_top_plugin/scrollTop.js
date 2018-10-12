function scrollToTop() {
	window.scrollTo(window.pageXOffset, 0);
}

function scrollToTopSmooth() {
	var y = window.pageYOffset;
	y *= 0.9;

	if (y <= 1) { y = 0; }

	window.scrollTo(window.pageXOffset, y);

	if (y != 0) {
		setTimeout(scrollToTopSmooth, 16);
	}
}
