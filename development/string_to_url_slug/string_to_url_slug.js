function string_to_url_slug(title)
{
  //First step: replace uppercase letters with lowercase + accents like "éèàüöä" with "eeauoa" + replace "&" with "and" WITHOUT USING .replace
  let inStringArray = title.split("");
  let outStringArray = [];
  let inSpecialCharArray = "àáäâãåèéëêìíïîòóöôùúüûñçßÿœæŕśńṕẃǵǹḿǘẍźḧŠŽšžŸÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖÙÚÛÜÝ".split("");
  let outSpecialCharArray = "aaaaaaeeeeiiiioooouuuuncsyoarsnpwgnmuxzhSZszYAAAAAACEEEEIIIIDNOOOOOUUUUY".split("");

  inStringArray.forEach((c) =>
  {
    if (inSpecialCharArray.includes(c))
    {
      outStringArray.push(outSpecialCharArray[inSpecialCharArray.indexOf(c)]);
    }
    else if (c == "&")
    {
      outStringArray.push("and")
    }
    else
    {
      outStringArray.push(c.toLowerCase());
    }
  });

  //Second step: filter all non alphanumeric characters and replace blank spaces with "-"
  let url_slug = outStringArray.filter((c) =>
  {
    let pattern = RegExp("\\w|\\s");
    return pattern.test(c);
  }).join("").split(" ").join("-");

  return url_slug;
}
