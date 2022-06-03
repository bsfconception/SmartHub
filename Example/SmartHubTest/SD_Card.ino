#ifdef __MANAGE_SDCARD__


/****************************************************************************/

int _SD_MountSDCard()
{
  //Assuming use of SPI SD card
#ifdef __MANAGE_OLED__
  SPI2.begin(_SD_SCLK, _SD_MISO, _SD_MOSI, _SD_CS);
  if (!SD.begin(_SD_CS, SPI2)) 
#else
  SPIClass& spi = g_Display.getSPIinstance();
  if (!SD.begin(_SD_CS, spi )) 
#endif  
  {
    #ifdef __DEBUG__
      g_SerialDebug.println("SDCard Mount Failed");
    #endif  
    return(0);
  } 
  else 
  {
    String siz = String((uint32_t)(SD.cardSize() / 1024 / 1024)) + "MB";
    #ifdef __DEBUG__
      g_SerialDebug.print("SDCard Mount PASS : ");
      g_SerialDebug.println(siz);
    #endif  
      
  }
  return(1);    
}

/****************************************************************************/

long SD_GetCardSize( void )
{
long s;
  s = SD.cardSize();
  return(s);
}

void _SD_createDir(fs::FS &fs, const char * path){
    g_SerialDebug.printf("Creating Dir: %s\n", path);
    if(fs.mkdir(path)){
        g_SerialDebug.println("Dir created");
    } else {
        g_SerialDebug.println("mkdir failed");
    }
}

void _SD_removeDir(fs::FS &fs, const char * path){
    g_SerialDebug.printf("Removing Dir: %s\n", path);
    if(fs.rmdir(path)){
        g_SerialDebug.println("Dir removed");
    } else {
        g_SerialDebug.println("rmdir failed");
    }
}

void _SD_readFile(fs::FS &fs, const char * path){
    g_SerialDebug.printf("Reading file: %s\n", path);

    File file = fs.open(path);
    if(!file){
        g_SerialDebug.println("Failed to open file for reading");
        return;
    }

    g_SerialDebug.print("Read from file: ");
    while(file.available()){
        g_SerialDebug.write(file.read());
    }
    file.close();
}

void _SD_writeFile(fs::FS &fs, const char * path, const char * message){
   g_SerialDebug.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        g_SerialDebug.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        g_SerialDebug.println("File written");
    } else {
        g_SerialDebug.println("Write failed");
    }
    file.close();
}

void _SD_appendFile(fs::FS &fs, const char * path, const char * message){
    g_SerialDebug.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        g_SerialDebug.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        g_SerialDebug.println("Message appended");
    } else {
        g_SerialDebug.println("Append failed");
    }
    file.close();
}

void _SD_renameFile(fs::FS &fs, const char * path1, const char * path2){
    g_SerialDebug.printf("Renaming file %s to %s\n", path1, path2);
    if (fs.rename(path1, path2)) {
        g_SerialDebug.println("File renamed");
    } else {
        g_SerialDebug.println("Rename failed");
    }
}

void _SD_deleteFile(fs::FS &fs, const char * path){
    g_SerialDebug.printf("Deleting file: %s\n", path);
    if(fs.remove(path)){
        g_SerialDebug.println("File deleted");
    } else {
        g_SerialDebug.println("Delete failed");
    }
}



#endif
