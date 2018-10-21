#/usr/bin/bash

################################################################
### subscription key for using the bing api
SUBS_KEY="###"

### api url to use
API_LINK="https://api.cognitive.microsoft.com/bing/v7.0/images/search?q=$1&count=$2&offset=0&mkt=en-us&safeSearch=Moderate"

### intermediate results will be saved
### comment out the rm at the end, for debugging purposes
RESPONSE_FILE="response.txt"
JSON_FILE="content.json"
PIC_FILE="tmp_file"
################################################################



### check command line args
if [ "$#" -ne 2 ]; then
    echo "usage: ./image_search <QUERY> <N>\n"
    echo "<QUERY>: keyword to search"
    echo "<N>: number of results"
fi

### check subscription key
if [ $SUBS_KEY = "###" ]; then
    echo "please enter a valid subscription key"
    echo "see here: https://azure.microsoft.com/en-in/services/cognitive-services/bing-image-search-api/"
    exit 1
fi


### obtain the request from the api
RESPONSE=$(curl --silent -i -H "Ocp-Apim-Subscription-Key:$SUBS_KEY" $API_LINK -o $RESPONSE_FILE)


### check the http status from the response
HTTP_STATUS=$(cat $RESPONSE_FILE | grep 'HTTP' | awk '{print $2}')
if [ "$HTTP_STATUS" -ne 200 ]; then
    echo "Error: "$HTTP_STATUS
    echo "please see file: "$RESPONSE_FILE 
    exit 2
fi


### if the response is ok, last line is the json part
JSON=$(cat $RESPONSE_FILE | tail -n 1)
echo $JSON > $JSON_FILE


### get the links
URL_LIST=$(cat $JSON_FILE | jq -r '.value[].contentUrl') 

### for each link, download the image to $PIC_FILE and catpix it
COUNT=1
for link in $(echo $URL_LIST)
do
  echo $COUNT
  curl --silent -o $PIC_FILE "$link"
  catpix $PIC_FILE
  COUNT=$((COUNT+1))
  echo ""
done


### clean-up
rm $RESPONSE_FILE $JSON_FILE $PIC_FILE
