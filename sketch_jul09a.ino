#include<WiFi.h>
#include<SD.h>
#include <ImgurUploader.h>
//#include "assets.h" //your image file.
void setup()
{
  #define IMGUR_CLIENT_ID "2887b9dd81b16c2" //your client_id created from the imgur website which you have to create using "https://api.imgur.com/oauth2/addclient" and using instructions of "https://apidocs.imgur.com/#authorization-and-oauth".


#ifndef IMGUR_CLIENT_ID
  #error "No client ID defined, see how to get one at https://medium.com/@microaeris/getting-started-with-the-imgur-api-4e96c352658a"
#endif


#define TFCARD_CS_PIN 4

ImgurUploader imgurUploader( IMGUR_CLIENT_ID );


WiFi.connect();
int ret = imgurUploader.uploadFile( SD, "/pic.jpg" );
//int ret = imgurUploader.uploadStream( 12345678, &writeStreamCallback, "pic.jpg", "image/jpeg" );//try this if before line doesn't work.
if( ret > 0 ) 
{
  Serial.println( imgurUploader.getURL() );
} 
else 
{
  Serial.println( "Upload failed" );
}




void loop() {
  

}
