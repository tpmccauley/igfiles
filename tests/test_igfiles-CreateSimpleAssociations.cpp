#ifdef PROJECT_NAME
# include <Iguana/interface/IgCollection.h>
#else
# include <IgCollection.h>
#endif
#include <iostream>

#include <cassert>

void
doTestCreateSimpleAssociations()
{
  IgDataStorage storage;
  // Create a collection of tracks.
  IgCollection &tracks = storage.getCollection("Tracks/V1");
  IgProperty X = tracks.addProperty("x", 0.0);
  IgProperty Y = tracks.addProperty("y", 0.0);
  IgProperty Z = tracks.addProperty("z", 0.0);
  IgProperty P_X = tracks.addProperty("px", 1.0);
  IgProperty P_Y = tracks.addProperty("py", 0.0);
  IgProperty P_Z = tracks.addProperty("pz", 0.0);

  // Create a collection for clusters.
  IgCollection &clusters = storage.getCollection("Clusters/V1");
  IgProperty C_X = clusters.addProperty("x", 0.0);
  IgProperty C_Y = clusters.addProperty("y", 0.0);
  IgProperty C_Z = clusters.addProperty("z", 0.0);
  IgProperty C_E = clusters.addProperty("e", 0.0);

  // Add a few tracks.
  for (int i = 0; i < 10 ; i++)
  {
    IgCollectionItem t = tracks.create();
    t[X] = static_cast<double>(i);
    t[Y] = static_cast<double>(i);
    t[Z] = static_cast<double>(i);
    t[P_X] = static_cast<double>(i);
    t[P_Y] = static_cast<double>(i);
    t[P_Z] = static_cast<double>(i);
  }

  // Add a few clusters.
  for (int i = 0; i < 10 ; i++)
  {
    IgCollectionItem c = clusters.create();
    c[C_X] = static_cast<double>(i);
    c[C_Y] = static_cast<double>(i);
    c[C_Z] = static_cast<double>(i);
    c[C_E] = static_cast<double>(i);
  }

  // One to one associations
  {
    IgAssociations &trackClusters = storage.getAssociations("TrackClusters/V1");

    IgCollection::iterator c = clusters.begin();
    IgCollection::iterator t = tracks.begin();

    while((c != clusters.end()) && (t != tracks.end()))
    {
      trackClusters.associate (*t, *c);
      t++;
      c++;
    }
    assert(trackClusters.size() == 10);
  }
  // One to many
  {
    IgAssociations &trackClusters = storage.getAssociations("TrackClusters2/V1");

    IgCollection::iterator c = clusters.begin();
    IgCollection::iterator t = tracks.begin();

    while((c != clusters.end()) && (t != tracks.end()))
    {
      trackClusters.associate (*t, *c);
      t++;
    }
  }
  // Writing out in Ig JSON based format.
  std::cerr << storage << std::endl;
}
