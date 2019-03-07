// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIworkdImdImizhoudIESdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIxAODHIEventdIobjdIxAODHIEvent_Reflex

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

#include "TBuffer.h"
#include "TVirtualObject.h"
#include <vector>
#include "TSchemaHelper.h"


// Header files passed as explicit arguments
#include "/afs/cern.ch/work/m/mizhou/ES/xAODHIEvent/xAODHIEvent/xAODHIEventDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *xAODcLcLHIEventShape_v1_Dictionary();
   static void xAODcLcLHIEventShape_v1_TClassManip(TClass*);
   static void *new_xAODcLcLHIEventShape_v1(void *p = 0);
   static void *newArray_xAODcLcLHIEventShape_v1(Long_t size, void *p);
   static void delete_xAODcLcLHIEventShape_v1(void *p);
   static void deleteArray_xAODcLcLHIEventShape_v1(void *p);
   static void destruct_xAODcLcLHIEventShape_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::HIEventShape_v1*)
   {
      ::xAOD::HIEventShape_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::HIEventShape_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::HIEventShape_v1", "xAODHIEvent/versions/HIEventShape_v1.h", 18,
                  typeid(::xAOD::HIEventShape_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLHIEventShape_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::HIEventShape_v1) );
      instance.SetNew(&new_xAODcLcLHIEventShape_v1);
      instance.SetNewArray(&newArray_xAODcLcLHIEventShape_v1);
      instance.SetDelete(&delete_xAODcLcLHIEventShape_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLHIEventShape_v1);
      instance.SetDestructor(&destruct_xAODcLcLHIEventShape_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::HIEventShape_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::HIEventShape_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::HIEventShape_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLHIEventShape_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::HIEventShape_v1*)0x0)->GetClass();
      xAODcLcLHIEventShape_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLHIEventShape_v1_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLHIEventShape_v1gR_Dictionary();
   static void DataVectorlExAODcLcLHIEventShape_v1gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLHIEventShape_v1gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLHIEventShape_v1gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLHIEventShape_v1gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLHIEventShape_v1gR(void *p);
   static void destruct_DataVectorlExAODcLcLHIEventShape_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::HIEventShape_v1>*)
   {
      ::DataVector<xAOD::HIEventShape_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::HIEventShape_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::HIEventShape_v1>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::HIEventShape_v1>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLHIEventShape_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::HIEventShape_v1>) );
      instance.SetNew(&new_DataVectorlExAODcLcLHIEventShape_v1gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLHIEventShape_v1gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLHIEventShape_v1gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLHIEventShape_v1gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLHIEventShape_v1gR);

      ROOT::AddClassAlternate("DataVector<xAOD::HIEventShape_v1>","xAOD::HIEventShapeContainer_v1");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::HIEventShape_v1>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::HIEventShape_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::HIEventShape_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLHIEventShape_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::HIEventShape_v1>*)0x0)->GetClass();
      DataVectorlExAODcLcLHIEventShape_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLHIEventShape_v1gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","FA2C3CB2-71A6-11E4-BB30-02163E010E29");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLHIEventShapeAuxContainer_v1_Dictionary();
   static void xAODcLcLHIEventShapeAuxContainer_v1_TClassManip(TClass*);
   static void *new_xAODcLcLHIEventShapeAuxContainer_v1(void *p = 0);
   static void *newArray_xAODcLcLHIEventShapeAuxContainer_v1(Long_t size, void *p);
   static void delete_xAODcLcLHIEventShapeAuxContainer_v1(void *p);
   static void deleteArray_xAODcLcLHIEventShapeAuxContainer_v1(void *p);
   static void destruct_xAODcLcLHIEventShapeAuxContainer_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::HIEventShapeAuxContainer_v1*)
   {
      ::xAOD::HIEventShapeAuxContainer_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::HIEventShapeAuxContainer_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::HIEventShapeAuxContainer_v1", "xAODHIEvent/versions/HIEventShapeAuxContainer_v1.h", 10,
                  typeid(::xAOD::HIEventShapeAuxContainer_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLHIEventShapeAuxContainer_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::HIEventShapeAuxContainer_v1) );
      instance.SetNew(&new_xAODcLcLHIEventShapeAuxContainer_v1);
      instance.SetNewArray(&newArray_xAODcLcLHIEventShapeAuxContainer_v1);
      instance.SetDelete(&delete_xAODcLcLHIEventShapeAuxContainer_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLHIEventShapeAuxContainer_v1);
      instance.SetDestructor(&destruct_xAODcLcLHIEventShapeAuxContainer_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::HIEventShapeAuxContainer_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::HIEventShapeAuxContainer_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::HIEventShapeAuxContainer_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLHIEventShapeAuxContainer_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::HIEventShapeAuxContainer_v1*)0x0)->GetClass();
      xAODcLcLHIEventShapeAuxContainer_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLHIEventShapeAuxContainer_v1_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","06FA81A6-71A7-11E4-9A9D-02163E010E29");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklExAODcLcLHIEventShape_v1gR_Dictionary();
   static void DataLinklExAODcLcLHIEventShape_v1gR_TClassManip(TClass*);
   static void *new_DataLinklExAODcLcLHIEventShape_v1gR(void *p = 0);
   static void *newArray_DataLinklExAODcLcLHIEventShape_v1gR(Long_t size, void *p);
   static void delete_DataLinklExAODcLcLHIEventShape_v1gR(void *p);
   static void deleteArray_DataLinklExAODcLcLHIEventShape_v1gR(void *p);
   static void destruct_DataLinklExAODcLcLHIEventShape_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<xAOD::HIEventShape_v1>*)
   {
      ::DataLink<xAOD::HIEventShape_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<xAOD::HIEventShape_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<xAOD::HIEventShape_v1>", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<xAOD::HIEventShape_v1>), DefineBehavior(ptr, ptr),
                  &DataLinklExAODcLcLHIEventShape_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<xAOD::HIEventShape_v1>) );
      instance.SetNew(&new_DataLinklExAODcLcLHIEventShape_v1gR);
      instance.SetNewArray(&newArray_DataLinklExAODcLcLHIEventShape_v1gR);
      instance.SetDelete(&delete_DataLinklExAODcLcLHIEventShape_v1gR);
      instance.SetDeleteArray(&deleteArray_DataLinklExAODcLcLHIEventShape_v1gR);
      instance.SetDestructor(&destruct_DataLinklExAODcLcLHIEventShape_v1gR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<xAOD::HIEventShape_v1>*)
   {
      return GenerateInitInstanceLocal((::DataLink<xAOD::HIEventShape_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<xAOD::HIEventShape_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklExAODcLcLHIEventShape_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<xAOD::HIEventShape_v1>*)0x0)->GetClass();
      DataLinklExAODcLcLHIEventShape_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklExAODcLcLHIEventShape_v1gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)
   {
      ::ElementLink<DataVector<xAOD::HIEventShape_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::HIEventShape_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::HIEventShape_v1> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::HIEventShape_v1> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::HIEventShape_v1> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::HIEventShape_v1> >","ElementLink<xAOD::HIEventShapeContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLHIEventShape_v2_Dictionary();
   static void xAODcLcLHIEventShape_v2_TClassManip(TClass*);
   static void *new_xAODcLcLHIEventShape_v2(void *p = 0);
   static void *newArray_xAODcLcLHIEventShape_v2(Long_t size, void *p);
   static void delete_xAODcLcLHIEventShape_v2(void *p);
   static void deleteArray_xAODcLcLHIEventShape_v2(void *p);
   static void destruct_xAODcLcLHIEventShape_v2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::HIEventShape_v2*)
   {
      ::xAOD::HIEventShape_v2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::HIEventShape_v2));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::HIEventShape_v2", "xAODHIEvent/versions/HIEventShape_v2.h", 26,
                  typeid(::xAOD::HIEventShape_v2), DefineBehavior(ptr, ptr),
                  &xAODcLcLHIEventShape_v2_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::HIEventShape_v2) );
      instance.SetNew(&new_xAODcLcLHIEventShape_v2);
      instance.SetNewArray(&newArray_xAODcLcLHIEventShape_v2);
      instance.SetDelete(&delete_xAODcLcLHIEventShape_v2);
      instance.SetDeleteArray(&deleteArray_xAODcLcLHIEventShape_v2);
      instance.SetDestructor(&destruct_xAODcLcLHIEventShape_v2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::HIEventShape_v2*)
   {
      return GenerateInitInstanceLocal((::xAOD::HIEventShape_v2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::HIEventShape_v2*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLHIEventShape_v2_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::HIEventShape_v2*)0x0)->GetClass();
      xAODcLcLHIEventShape_v2_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLHIEventShape_v2_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLHIEventShape_v2gR_Dictionary();
   static void DataVectorlExAODcLcLHIEventShape_v2gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLHIEventShape_v2gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLHIEventShape_v2gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLHIEventShape_v2gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLHIEventShape_v2gR(void *p);
   static void destruct_DataVectorlExAODcLcLHIEventShape_v2gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::HIEventShape_v2>*)
   {
      ::DataVector<xAOD::HIEventShape_v2> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::HIEventShape_v2>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::HIEventShape_v2>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::HIEventShape_v2>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLHIEventShape_v2gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::HIEventShape_v2>) );
      instance.SetNew(&new_DataVectorlExAODcLcLHIEventShape_v2gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLHIEventShape_v2gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLHIEventShape_v2gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLHIEventShape_v2gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLHIEventShape_v2gR);

      ROOT::AddClassAlternate("DataVector<xAOD::HIEventShape_v2>","xAOD::HIEventShapeContainer_v2");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::HIEventShape_v2>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::HIEventShape_v2>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::HIEventShape_v2>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLHIEventShape_v2gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::HIEventShape_v2>*)0x0)->GetClass();
      DataVectorlExAODcLcLHIEventShape_v2gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLHIEventShape_v2gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","386D4EAA-358E-42CB-B35C-126D69D1331C");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLHIEventShapeAuxContainer_v2_Dictionary();
   static void xAODcLcLHIEventShapeAuxContainer_v2_TClassManip(TClass*);
   static void *new_xAODcLcLHIEventShapeAuxContainer_v2(void *p = 0);
   static void *newArray_xAODcLcLHIEventShapeAuxContainer_v2(Long_t size, void *p);
   static void delete_xAODcLcLHIEventShapeAuxContainer_v2(void *p);
   static void deleteArray_xAODcLcLHIEventShapeAuxContainer_v2(void *p);
   static void destruct_xAODcLcLHIEventShapeAuxContainer_v2(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::HIEventShapeAuxContainer_v2*)
   {
      ::xAOD::HIEventShapeAuxContainer_v2 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::HIEventShapeAuxContainer_v2));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::HIEventShapeAuxContainer_v2", "xAODHIEvent/versions/HIEventShapeAuxContainer_v2.h", 26,
                  typeid(::xAOD::HIEventShapeAuxContainer_v2), DefineBehavior(ptr, ptr),
                  &xAODcLcLHIEventShapeAuxContainer_v2_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::HIEventShapeAuxContainer_v2) );
      instance.SetNew(&new_xAODcLcLHIEventShapeAuxContainer_v2);
      instance.SetNewArray(&newArray_xAODcLcLHIEventShapeAuxContainer_v2);
      instance.SetDelete(&delete_xAODcLcLHIEventShapeAuxContainer_v2);
      instance.SetDeleteArray(&deleteArray_xAODcLcLHIEventShapeAuxContainer_v2);
      instance.SetDestructor(&destruct_xAODcLcLHIEventShapeAuxContainer_v2);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::HIEventShapeAuxContainer_v2*)
   {
      return GenerateInitInstanceLocal((::xAOD::HIEventShapeAuxContainer_v2*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::HIEventShapeAuxContainer_v2*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLHIEventShapeAuxContainer_v2_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::HIEventShapeAuxContainer_v2*)0x0)->GetClass();
      xAODcLcLHIEventShapeAuxContainer_v2_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLHIEventShapeAuxContainer_v2_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","8A34CCBF-509A-4A15-8234-07FBC0BFF1B0");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklExAODcLcLHIEventShape_v2gR_Dictionary();
   static void DataLinklExAODcLcLHIEventShape_v2gR_TClassManip(TClass*);
   static void *new_DataLinklExAODcLcLHIEventShape_v2gR(void *p = 0);
   static void *newArray_DataLinklExAODcLcLHIEventShape_v2gR(Long_t size, void *p);
   static void delete_DataLinklExAODcLcLHIEventShape_v2gR(void *p);
   static void deleteArray_DataLinklExAODcLcLHIEventShape_v2gR(void *p);
   static void destruct_DataLinklExAODcLcLHIEventShape_v2gR(void *p);

   // Schema evolution read functions

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<xAOD::HIEventShape_v2>*)
   {
      ::DataLink<xAOD::HIEventShape_v2> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<xAOD::HIEventShape_v2>));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<xAOD::HIEventShape_v2>", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<xAOD::HIEventShape_v2>), DefineBehavior(ptr, ptr),
                  &DataLinklExAODcLcLHIEventShape_v2gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<xAOD::HIEventShape_v2>) );
      instance.SetNew(&new_DataLinklExAODcLcLHIEventShape_v2gR);
      instance.SetNewArray(&newArray_DataLinklExAODcLcLHIEventShape_v2gR);
      instance.SetDelete(&delete_DataLinklExAODcLcLHIEventShape_v2gR);
      instance.SetDeleteArray(&deleteArray_DataLinklExAODcLcLHIEventShape_v2gR);
      instance.SetDestructor(&destruct_DataLinklExAODcLcLHIEventShape_v2gR);

      ROOT::TSchemaHelper* rule;

      // the io read rules
      std::vector<ROOT::TSchemaHelper> readrules(1);
      rule = &readrules[0];
      rule->fSourceClass = "DataLink<xAOD::HIEventShape_v1>";
      rule->fTarget      = "";
      rule->fSource      = "";
      rule->fVersion     = "[1-]";
      instance.SetReadRules( readrules );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<xAOD::HIEventShape_v2>*)
   {
      return GenerateInitInstanceLocal((::DataLink<xAOD::HIEventShape_v2>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<xAOD::HIEventShape_v2>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklExAODcLcLHIEventShape_v2gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<xAOD::HIEventShape_v2>*)0x0)->GetClass();
      DataLinklExAODcLcLHIEventShape_v2gR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklExAODcLcLHIEventShape_v2gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)
   {
      ::ElementLink<DataVector<xAOD::HIEventShape_v2> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::HIEventShape_v2> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::HIEventShape_v2> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::HIEventShape_v2> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::HIEventShape_v2> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::HIEventShape_v2> >","ElementLink<xAOD::HIEventShapeContainer_v2>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLHIEventShape_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShape_v1 : new ::xAOD::HIEventShape_v1;
   }
   static void *newArray_xAODcLcLHIEventShape_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShape_v1[nElements] : new ::xAOD::HIEventShape_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLHIEventShape_v1(void *p) {
      delete ((::xAOD::HIEventShape_v1*)p);
   }
   static void deleteArray_xAODcLcLHIEventShape_v1(void *p) {
      delete [] ((::xAOD::HIEventShape_v1*)p);
   }
   static void destruct_xAODcLcLHIEventShape_v1(void *p) {
      typedef ::xAOD::HIEventShape_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::HIEventShape_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLHIEventShape_v1gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::HIEventShape_v1> : new ::DataVector<xAOD::HIEventShape_v1>;
   }
   static void *newArray_DataVectorlExAODcLcLHIEventShape_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::HIEventShape_v1>[nElements] : new ::DataVector<xAOD::HIEventShape_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLHIEventShape_v1gR(void *p) {
      delete ((::DataVector<xAOD::HIEventShape_v1>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLHIEventShape_v1gR(void *p) {
      delete [] ((::DataVector<xAOD::HIEventShape_v1>*)p);
   }
   static void destruct_DataVectorlExAODcLcLHIEventShape_v1gR(void *p) {
      typedef ::DataVector<xAOD::HIEventShape_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::HIEventShape_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLHIEventShapeAuxContainer_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShapeAuxContainer_v1 : new ::xAOD::HIEventShapeAuxContainer_v1;
   }
   static void *newArray_xAODcLcLHIEventShapeAuxContainer_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShapeAuxContainer_v1[nElements] : new ::xAOD::HIEventShapeAuxContainer_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLHIEventShapeAuxContainer_v1(void *p) {
      delete ((::xAOD::HIEventShapeAuxContainer_v1*)p);
   }
   static void deleteArray_xAODcLcLHIEventShapeAuxContainer_v1(void *p) {
      delete [] ((::xAOD::HIEventShapeAuxContainer_v1*)p);
   }
   static void destruct_xAODcLcLHIEventShapeAuxContainer_v1(void *p) {
      typedef ::xAOD::HIEventShapeAuxContainer_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::HIEventShapeAuxContainer_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklExAODcLcLHIEventShape_v1gR(void *p) {
      return  p ? new(p) ::DataLink<xAOD::HIEventShape_v1> : new ::DataLink<xAOD::HIEventShape_v1>;
   }
   static void *newArray_DataLinklExAODcLcLHIEventShape_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<xAOD::HIEventShape_v1>[nElements] : new ::DataLink<xAOD::HIEventShape_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklExAODcLcLHIEventShape_v1gR(void *p) {
      delete ((::DataLink<xAOD::HIEventShape_v1>*)p);
   }
   static void deleteArray_DataLinklExAODcLcLHIEventShape_v1gR(void *p) {
      delete [] ((::DataLink<xAOD::HIEventShape_v1>*)p);
   }
   static void destruct_DataLinklExAODcLcLHIEventShape_v1gR(void *p) {
      typedef ::DataLink<xAOD::HIEventShape_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<xAOD::HIEventShape_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::HIEventShape_v1> > : new ::ElementLink<DataVector<xAOD::HIEventShape_v1> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::HIEventShape_v1> >[nElements] : new ::ElementLink<DataVector<xAOD::HIEventShape_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::HIEventShape_v1> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::HIEventShape_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::HIEventShape_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLHIEventShape_v2(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShape_v2 : new ::xAOD::HIEventShape_v2;
   }
   static void *newArray_xAODcLcLHIEventShape_v2(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShape_v2[nElements] : new ::xAOD::HIEventShape_v2[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLHIEventShape_v2(void *p) {
      delete ((::xAOD::HIEventShape_v2*)p);
   }
   static void deleteArray_xAODcLcLHIEventShape_v2(void *p) {
      delete [] ((::xAOD::HIEventShape_v2*)p);
   }
   static void destruct_xAODcLcLHIEventShape_v2(void *p) {
      typedef ::xAOD::HIEventShape_v2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::HIEventShape_v2

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLHIEventShape_v2gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::HIEventShape_v2> : new ::DataVector<xAOD::HIEventShape_v2>;
   }
   static void *newArray_DataVectorlExAODcLcLHIEventShape_v2gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::HIEventShape_v2>[nElements] : new ::DataVector<xAOD::HIEventShape_v2>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLHIEventShape_v2gR(void *p) {
      delete ((::DataVector<xAOD::HIEventShape_v2>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLHIEventShape_v2gR(void *p) {
      delete [] ((::DataVector<xAOD::HIEventShape_v2>*)p);
   }
   static void destruct_DataVectorlExAODcLcLHIEventShape_v2gR(void *p) {
      typedef ::DataVector<xAOD::HIEventShape_v2> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::HIEventShape_v2>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLHIEventShapeAuxContainer_v2(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShapeAuxContainer_v2 : new ::xAOD::HIEventShapeAuxContainer_v2;
   }
   static void *newArray_xAODcLcLHIEventShapeAuxContainer_v2(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::HIEventShapeAuxContainer_v2[nElements] : new ::xAOD::HIEventShapeAuxContainer_v2[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLHIEventShapeAuxContainer_v2(void *p) {
      delete ((::xAOD::HIEventShapeAuxContainer_v2*)p);
   }
   static void deleteArray_xAODcLcLHIEventShapeAuxContainer_v2(void *p) {
      delete [] ((::xAOD::HIEventShapeAuxContainer_v2*)p);
   }
   static void destruct_xAODcLcLHIEventShapeAuxContainer_v2(void *p) {
      typedef ::xAOD::HIEventShapeAuxContainer_v2 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::HIEventShapeAuxContainer_v2

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklExAODcLcLHIEventShape_v2gR(void *p) {
      return  p ? new(p) ::DataLink<xAOD::HIEventShape_v2> : new ::DataLink<xAOD::HIEventShape_v2>;
   }
   static void *newArray_DataLinklExAODcLcLHIEventShape_v2gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<xAOD::HIEventShape_v2>[nElements] : new ::DataLink<xAOD::HIEventShape_v2>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklExAODcLcLHIEventShape_v2gR(void *p) {
      delete ((::DataLink<xAOD::HIEventShape_v2>*)p);
   }
   static void deleteArray_DataLinklExAODcLcLHIEventShape_v2gR(void *p) {
      delete [] ((::DataLink<xAOD::HIEventShape_v2>*)p);
   }
   static void destruct_DataLinklExAODcLcLHIEventShape_v2gR(void *p) {
      typedef ::DataLink<xAOD::HIEventShape_v2> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<xAOD::HIEventShape_v2>

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::HIEventShape_v2> > : new ::ElementLink<DataVector<xAOD::HIEventShape_v2> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::HIEventShape_v2> >[nElements] : new ::ElementLink<DataVector<xAOD::HIEventShape_v2> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::HIEventShape_v2> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::HIEventShape_v2> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::HIEventShape_v2> >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > > : new vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > > : new vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >*)
   {
      vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > : new vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >[nElements] : new vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v2gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >*)
   {
      vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > : new vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >[nElements] : new vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLHIEventShape_v1gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >

namespace ROOT {
   static TClass *vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_Dictionary();
   static void vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p);
   static void destruct_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<xAOD::HIEventShape_v2> >*)
   {
      vector<DataLink<xAOD::HIEventShape_v2> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<xAOD::HIEventShape_v2> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<xAOD::HIEventShape_v2> >", -2, "vector", 210,
                  typeid(vector<DataLink<xAOD::HIEventShape_v2> >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<xAOD::HIEventShape_v2> >) );
      instance.SetNew(&new_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<xAOD::HIEventShape_v2> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<xAOD::HIEventShape_v2> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<xAOD::HIEventShape_v2> >*)0x0)->GetClass();
      vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<xAOD::HIEventShape_v2> > : new vector<DataLink<xAOD::HIEventShape_v2> >;
   }
   static void *newArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<xAOD::HIEventShape_v2> >[nElements] : new vector<DataLink<xAOD::HIEventShape_v2> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      delete ((vector<DataLink<xAOD::HIEventShape_v2> >*)p);
   }
   static void deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      delete [] ((vector<DataLink<xAOD::HIEventShape_v2> >*)p);
   }
   static void destruct_vectorlEDataLinklExAODcLcLHIEventShape_v2gRsPgR(void *p) {
      typedef vector<DataLink<xAOD::HIEventShape_v2> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<xAOD::HIEventShape_v2> >

namespace ROOT {
   static TClass *vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_Dictionary();
   static void vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p);
   static void destruct_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<xAOD::HIEventShape_v1> >*)
   {
      vector<DataLink<xAOD::HIEventShape_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<xAOD::HIEventShape_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<xAOD::HIEventShape_v1> >", -2, "vector", 210,
                  typeid(vector<DataLink<xAOD::HIEventShape_v1> >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<xAOD::HIEventShape_v1> >) );
      instance.SetNew(&new_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<xAOD::HIEventShape_v1> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<xAOD::HIEventShape_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<xAOD::HIEventShape_v1> >*)0x0)->GetClass();
      vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<xAOD::HIEventShape_v1> > : new vector<DataLink<xAOD::HIEventShape_v1> >;
   }
   static void *newArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<xAOD::HIEventShape_v1> >[nElements] : new vector<DataLink<xAOD::HIEventShape_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      delete ((vector<DataLink<xAOD::HIEventShape_v1> >*)p);
   }
   static void deleteArray_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      delete [] ((vector<DataLink<xAOD::HIEventShape_v1> >*)p);
   }
   static void destruct_vectorlEDataLinklExAODcLcLHIEventShape_v1gRsPgR(void *p) {
      typedef vector<DataLink<xAOD::HIEventShape_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<xAOD::HIEventShape_v1> >

namespace {
  void TriggerDictionaryInitialization_xAODHIEvent_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/work/m/mizhou/ES/xAODHIEvent/Root",
"/afs/cern.ch/work/m/mizhou/ES/xAODHIEvent",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/work/m/mizhou/ES/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/work/m/mizhou/ES/xAODHIEvent/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODHIEvent/versions/HIEventShape_v1.h")))  HIEventShape_v1;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@06FA81A6-71A7-11E4-9A9D-02163E010E29)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODHIEvent/versions/HIEventShapeAuxContainer_v1.h")))  HIEventShapeAuxContainer_v1;}
template <typename STORABLE> class __attribute__((annotate("$clingAutoload$AthLinks/DataLink.h")))  DataLink;

namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODHIEvent/HIEventShape.h")))  HIEventShape_v2;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@8A34CCBF-509A-4A15-8234-07FBC0BFF1B0)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODHIEvent/HIEventShapeAuxContainer.h")))  HIEventShapeAuxContainer_v2;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 23
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630"
#endif
#ifndef ASG_TEST_FILE_DATA
  #define ASG_TEST_FILE_DATA "/afs/cern.ch/atlas/project/PAT/xAODs/p2410/data15_13TeV.00270448.physics_Main.merge.AOD.r6943_p2410/AOD.06297575._000522.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MC
  #define ASG_TEST_FILE_MC "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6630/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e3698_s2608_s2183_r6630_tid05352803_00/AOD.05352803._000242.pool.root.1"
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "xAODHIEvent"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Dear emacs, this is -*- c++ -*-
// $Id: xAODHIEventDict.h 693494 2015-09-07 14:59:45Z krasznaa $
#ifndef XAODHIEVENT_XAODHIEVENTDICT_H
#define XAODHIEVENT_XAODHIEVENTDICT_H

// System include(s):
#include <vector>
#include <set>

// EDM include(s):
#include "AthLinks/ElementLink.h"
#include "AthLinks/DataLink.h"

// Local include(s):
#include "xAODHIEvent/HIEventShape.h"
#include "xAODHIEvent/HIEventShapeContainer.h"
#include "xAODHIEvent/HIEventShapeAuxContainer.h"
#include "xAODHIEvent/versions/HIEventShape_v1.h"
#include "xAODHIEvent/versions/HIEventShapeContainer_v1.h"
#include "xAODHIEvent/versions/HIEventShapeAuxContainer_v1.h"
#include "xAODHIEvent/versions/HIEventShape_v2.h"
#include "xAODHIEvent/versions/HIEventShapeContainer_v2.h"
#include "xAODHIEvent/versions/HIEventShapeAuxContainer_v2.h"

/// Declare a dummy CLID for xAOD::HIEventShape_v1 and
/// xAOD::HIEventShapeContainer_v1. To be able to still
/// define/use smart pointers for them. For schema evolution purposes.
CLASS_DEF( xAOD::HIEventShape_v1, 11112222, 10 )
CLASS_DEF( xAOD::HIEventShapeContainer_v1, 22223333, 10 )

namespace {
   struct GCCXML_DUMMY_INSTANTIATION_XAODHIEVENT {

      xAOD::HIEventShapeContainer_v1 c1;
      xAOD::HIEventShapeContainer_v2 c2;

      DataLink< xAOD::HIEventShape_v1 > dl1;
      std::vector< DataLink< xAOD::HIEventShape_v1 > > dl2;
      DataLink< xAOD::HIEventShape_v2 > dl3;
      std::vector< DataLink< xAOD::HIEventShape_v2 > > dl4;

      ElementLink< xAOD::HIEventShapeContainer_v1 > el1;
      std::vector< ElementLink< xAOD::HIEventShapeContainer_v1 > > el2;
      std::vector< std::vector< ElementLink< xAOD::HIEventShapeContainer_v1 > > > el3;
      ElementLink< xAOD::HIEventShapeContainer_v2 > el4;
      std::vector< ElementLink< xAOD::HIEventShapeContainer_v2 > > el5;
      std::vector< std::vector< ElementLink< xAOD::HIEventShapeContainer_v2 > > > el6;

      std::set< uint32_t > set1;
      std::vector< std::set< uint32_t > > set2;

   };
} // private namespace

#endif // XAODEVENTINFO_XAODEVENTINFODICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"DataLink<xAOD::HIEventShape_v1>", payloadCode, "@",
"DataLink<xAOD::HIEventShape_v2>", payloadCode, "@",
"DataVector<xAOD::HIEventShape_v1>", payloadCode, "@",
"DataVector<xAOD::HIEventShape_v2>", payloadCode, "@",
"ElementLink<DataVector<xAOD::HIEventShape_v1> >", payloadCode, "@",
"ElementLink<DataVector<xAOD::HIEventShape_v2> >", payloadCode, "@",
"ElementLink<xAOD::HIEventShapeContainer_v1>", payloadCode, "@",
"ElementLink<xAOD::HIEventShapeContainer_v2>", payloadCode, "@",
"vector<DataLink<xAOD::HIEventShape_v1> >", payloadCode, "@",
"vector<DataLink<xAOD::HIEventShape_v2> >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > >", payloadCode, "@",
"vector<ElementLink<xAOD::HIEventShapeContainer_v1> >", payloadCode, "@",
"vector<ElementLink<xAOD::HIEventShapeContainer_v2> >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::HIEventShapeContainer_v1> > >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::HIEventShapeContainer_v2> > >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v1> > > >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::HIEventShape_v2> > > >", payloadCode, "@",
"xAOD::HIEventShapeAuxContainer_v1", payloadCode, "@",
"xAOD::HIEventShapeAuxContainer_v2", payloadCode, "@",
"xAOD::HIEventShapeContainer_v1", payloadCode, "@",
"xAOD::HIEventShapeContainer_v2", payloadCode, "@",
"xAOD::HIEventShape_v1", payloadCode, "@",
"xAOD::HIEventShape_v2", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("xAODHIEvent_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_xAODHIEvent_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_xAODHIEvent_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_xAODHIEvent_Reflex() {
  TriggerDictionaryInitialization_xAODHIEvent_Reflex_Impl();
}
