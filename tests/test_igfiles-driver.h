#ifndef TEST_IGFILES_DRIVER_H
#define TEST_IGFILES_DRIVER_H
#include <cassert>

extern void doTestCreateSimpleCollection();
extern void doTestCreateSimpleAssociations();
extern void doTestCreateSimpleAssociations02();
extern void doTestNavigateAssociations();
extern void doTestCreateWriteReadWriteReadPrintNoAssociations();
extern void doTestCreateReadWriteReadPrint();
extern void doTestNavigateAssociationsOneToOne();
extern void doTestNavigateOneAssociation();
extern void doTestCollectionPerformance();
extern void doTestLinearAlgebra();
extern void doTestCreateCollectionWriteZipFile();

struct IgCollectionTest
{
    void testCreateSimpleCollection(){doTestCreateSimpleCollection();}
    void testCreateSimpleAssociations(){doTestCreateSimpleAssociations();}
    void testCreateSimpleAssociations02(){doTestCreateSimpleAssociations02();}
    void testNavigateOneAssociation(){doTestNavigateOneAssociation();};
    void testNavigateAssociations(){doTestNavigateAssociations();}
    void testCreateWriteReadWriteReadPrintNoAssociations()
    {doTestCreateWriteReadWriteReadPrintNoAssociations();}
    void testCreateReadWriteReadPrint(){doTestCreateReadWriteReadPrint();}
    void testNavigateAssociationsOneToOne(){doTestNavigateAssociationsOneToOne();}
    //void testCollectionPerformance(){doTestCollectionPerformance();}
    void testLinearAlgebra(){doTestLinearAlgebra();}
    void testZipFile() { doTestCreateCollectionWriteZipFile(); }

    void run()
    {
      testCreateSimpleCollection();
      testCreateSimpleAssociations();
      testCreateSimpleAssociations02();
      testNavigateOneAssociation();
      testNavigateAssociations();
      testCreateWriteReadWriteReadPrintNoAssociations();
      testCreateReadWriteReadPrint();
      testNavigateAssociationsOneToOne();
      //testCollectionPerformance();
      testLinearAlgebra();
      testZipFile();
    }
};

#endif
