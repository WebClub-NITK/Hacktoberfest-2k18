# Horizontal loader

Displays a horizontal line loading animation along the topmost edge of the web page, similar to sites like Medium, YouTube and Flickr.

Original Github issue: [https://github.com/WebClub-NITK/Hacktoberfest-2k18/issues/22](https://github.com/WebClub-NITK/Hacktoberfest-2k18/issues/22)


## Setup

Include the JavaScript and CSS files on your page.


## Quick Example

You probably don't want to read lots of instructions just to get this working (although you'll be missing out on some pretty awesome features), so here's a quick and simple example of how to use *Horizontal Loader*:

``` javascript
// Displaying the horizontal loader at 60% complete
HorizontalLoader.init( 'loader' ).show().set( 60 );
```

Did you see how easy that was?

## Usage

For those of you who want to get the most out of *Horizontal Loader*, read on...

### Init

```javascript
HorizontalLoader.init( options );
```

Creates a *Horizontal Loader* instance on the page.

|Parameter|Type|Description|Example|Optional|
|---------|----|-----------|-------|--------|
|`options`|object|Any additional options to customize the *Horizontal Loader*|{}|Yes|

The object keys to use are listed below. All are optional:

|Parameter|Type|Description|Example|
|---------|----|-----------|-------|
|`loaderID`|string|An ID to give to the *Horizontal Loader*|loader|
|`parentContainer`|string|A valid DOM selector that the *Horizontal Loader* will be prepended as a child|.myDiv|
|`showIntermediateBlocks`|boolean|Should animated blocks be shown while the *Horizontal Loader* is showing|true|


### Show

```javascript
HorizontalLoader.show();
```

Makes the *Horizontal Loader* visible on the page.


### Hide

```javascript
HorizontalLoader.hide();
```

Makes the *Horizontal Loader* hidden on the page.


### Set

```javascript
HorizontalLoader.set( value, duration );
```

Sets the *Horizontal Loader* to be `value` percent completed, over `duration` time period.

|Parameter|Type|Description|Example|Optional|
|---------|----|-----------|-------|--------|
|`value`|integer|The percent completed amount the *Horizontal Loader* should show. Valid values are between `0` and `100` inclusive|60|No|
|`duration`|integer|How long the animation should take for the *Horizontal Loader* to show the value it has been set to. Any value less that 100 is assumed to be in seconds, otherwise it will use milliseconds. If nothing is passed, a default of 2 seconds is used|10|Yes|


### Get

```javascript
HorizontalLoader.get();
```

Gets the current percentage amount of the *Horizontal Loader*.


### Reset

```javascript
HorizontalLoader.reset();
```

Resets the *Horizontal Loader* to 0% complete. Shorthand for `HoriztonalLoader.set( 0, 0 )`.


### Increase

```javascript
HorizontalLoader.increase( amount, duration );
```

Increases the *Horizontal Loader* by `amount` (up to 100), over `duration` time period.

Useful for non-linear notification of progress (e.g. 10 checkboxes on a form and the user has to select any 5. Each one they select performs an increase of 20).

|Parameter|Type|Description|Example|Optional|
|---------|----|-----------|-------|--------|
|`amount`|integer|The amount to increase the *Horizontal Loader* from its current position. Valid values are between `0` and `100` inclusive|5|No|
|`duration`|integer|How long the animation should take for the *Horizontal Loader* to show the value it has been increased to. Any value less that 100 is assumed to be in seconds, otherwise it will use milliseconds. If nothing is passed, a default of 2 seconds is used|1500|Yes|


### Decrease

```javascript
HorizontalLoader.decrease( amount, duration );
```

Decreases the *Horizontal Loader* by `amount` (down to 0), over `duration` time period.

Useful for non-linear notification of progress (e.g. 10 checkboxes on a form and the user has to select any 5. Each one they deselect performs a decrease of 20).

|Parameter|Type|Description|Example|Optional|
|---------|----|-----------|-------|--------|
|`amount`|integer|The amount to decrease the *Horizontal Loader* from its current position. Valid values are between `0` and `100` inclusive|5|No|
|`duration`|integer|How long the animation should take for the *Horizontal Loader* to show the value it has been decreased to. Any value less that 100 is assumed to be in seconds, otherwise it will use milliseconds. If nothing is passed, a default of 2 seconds is used|1|Yes|


## Known Issues

### The *Horizontal Loader* is not animating

If you method chain after the [`init`](#init) function then no CSS animations will happen. This is due to [browser implementations](https://stackoverflow.com/a/24195559), so a workaround is to use a `setTimeout` function call.

```javascript
HorizontalLoader.init();
setTimeout( function() {
  HorizontalLoader.show().set( 60 );
}, 0 );
```

Any subsequent calls to `HorizontalLoader` functions will animate as expected.
