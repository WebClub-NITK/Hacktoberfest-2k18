# Scroll Top Plugin

A simple plugin that allows you to add a scroll to top button to your website. The button has a nice arrow icon. There a two versions, an instant jump and a smooth scroll to the top.

The plugin consists of two files `scrollTop.js` and `scrollTop.css`.
The `example.html` file contains a sample implementation.

## How to include

To use the plugin you have to include the javascript and css files in your html files. You can do that by adding the following to your html `<head>`.

```html
<link rel="stylesheet" type="text/css" href="scrollTop.css">
<script type="text/javascript" src="scrollTop.js"></script>
```

## How to use

You can create a button that jumps instantly to the top like this:
```html
<button class="scrollTopButton" onclick="scrollTop()">Top</button>
```

A button that moves slowly to the top is created like this:
```html
<button class="scrollTopButton" onclick="scrollTopSmooth()">Smooth to Top</button>
```
