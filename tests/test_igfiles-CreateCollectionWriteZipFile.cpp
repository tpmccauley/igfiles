#include <IgCollection.h>
#include <iostream>
#include <sstream>
#include <zip.h>

void
doTestCreateCollectionWriteZipFile()
{
  const char* filename = "createdFile.ig";
  int err = ZIP_OK;
  long int size_buf;
  void* buf;

  // Open zip file for writing
  zipFile zf = zipOpen(filename, APPEND_STATUS_CREATE);
  assert(zf != NULL);
   
  // Make 10 events in zip file
  for ( unsigned int i = 0, ie = 10; i != ie; ++i )
    {
      zip_fileinfo zi;
      
      // In usual use one must set these to 
      // proper time but leave 0 for now
      zi.tmz_date.tm_sec  = 0;
      zi.tmz_date.tm_min  = 0;
      zi.tmz_date.tm_hour = 0;
      zi.tmz_date.tm_mday = 0;
      zi.tmz_date.tm_mon  = 0;
      zi.tmz_date.tm_year = 0;

      zi.dosDate = 0;
      zi.internal_fa = 0;
      zi.external_fa = 0;

      // Create some simple IgCollections in IgDataStorage
      IgDataStorage* storage = new IgDataStorage;

      IgCollection& tracks = storage->getCollection("Tracks_V0");
      IgProperty X = tracks.addProperty("x", 0.0);
      IgProperty Y = tracks.addProperty("y", 0.0);
      IgProperty Z = tracks.addProperty("z", 0.0);
      IgProperty PX = tracks.addProperty("px", 0.0);
      IgProperty PY = tracks.addProperty("py", 0.0);
      IgProperty PZ = tracks.addProperty("pz", 0.0);

      // Create 10 events
      std::stringstream eoss;
      eoss << "Events/Run_1/Event_"<< i+1; 
      std::cout<< eoss.str() <<std::endl;

      err = zipOpenNewFileInZip(zf, // zipFile
				eoss.str().c_str(), // file name in zip
				&zi, // zip_fileinfo
				0,0,0,0,0, // other stuff
				Z_DEFLATED,
				9);
      
      assert(err == ZIP_OK);

      // Create tracks
      IgCollectionItem track = tracks.create();

      track[X] = i*0.5;
      track[Y] = i*0.5;
      track[Z] = i*0.5;
      
      track[PX] = 1.0;
      track[PY] = 0.0;
      track[PZ] = 0.0;

      std::stringstream doss;
      doss << *storage;
      //std::cout << doss.str().c_str() <<std::endl;

      size_buf = sizeof(std::string::size_type)+doss.str().length();
      buf = (void*) malloc(size_buf);
      memcpy((void*) buf, doss.str().c_str(), size_buf);
      assert(buf != NULL);
     
      err = zipWriteInFileInZip(zf, buf, size_buf);
      assert(err == ZIP_OK);

      err = zipCloseFileInZip(zf);      
      assert(err == ZIP_OK);

      free(buf);
      delete storage;
    }

  err = zipClose(zf, NULL);
  assert(err == ZIP_OK);
}
