// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIworkdImdImizhoudIRUN_FBdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIxAODForwarddIobjdIxAODForward_Reflex

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

// Header files passed as explicit arguments
#include "/afs/cern.ch/work/m/mizhou/RUN_FB/xAODForward/xAODForward/xAODForwardDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *xAODcLcLALFAData_v1_Dictionary();
   static void xAODcLcLALFAData_v1_TClassManip(TClass*);
   static void *new_xAODcLcLALFAData_v1(void *p = 0);
   static void *newArray_xAODcLcLALFAData_v1(Long_t size, void *p);
   static void delete_xAODcLcLALFAData_v1(void *p);
   static void deleteArray_xAODcLcLALFAData_v1(void *p);
   static void destruct_xAODcLcLALFAData_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ALFAData_v1*)
   {
      ::xAOD::ALFAData_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ALFAData_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ALFAData_v1", "xAODForward/versions/ALFAData_v1.h", 21,
                  typeid(::xAOD::ALFAData_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLALFAData_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ALFAData_v1) );
      instance.SetNew(&new_xAODcLcLALFAData_v1);
      instance.SetNewArray(&newArray_xAODcLcLALFAData_v1);
      instance.SetDelete(&delete_xAODcLcLALFAData_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLALFAData_v1);
      instance.SetDestructor(&destruct_xAODcLcLALFAData_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ALFAData_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ALFAData_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ALFAData_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLALFAData_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ALFAData_v1*)0x0)->GetClass();
      xAODcLcLALFAData_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLALFAData_v1_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLALFAData_v1gR_Dictionary();
   static void DataVectorlExAODcLcLALFAData_v1gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLALFAData_v1gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLALFAData_v1gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLALFAData_v1gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLALFAData_v1gR(void *p);
   static void destruct_DataVectorlExAODcLcLALFAData_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::ALFAData_v1>*)
   {
      ::DataVector<xAOD::ALFAData_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::ALFAData_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::ALFAData_v1>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::ALFAData_v1>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLALFAData_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::ALFAData_v1>) );
      instance.SetNew(&new_DataVectorlExAODcLcLALFAData_v1gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLALFAData_v1gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLALFAData_v1gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLALFAData_v1gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLALFAData_v1gR);

      ROOT::AddClassAlternate("DataVector<xAOD::ALFAData_v1>","xAOD::ALFADataContainer_v1");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::ALFAData_v1>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::ALFAData_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::ALFAData_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLALFAData_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::ALFAData_v1>*)0x0)->GetClass();
      DataVectorlExAODcLcLALFAData_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLALFAData_v1gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","8D245B28-F246-42D7-BD85-054A757D2A13");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLALFADataAuxContainer_v1_Dictionary();
   static void xAODcLcLALFADataAuxContainer_v1_TClassManip(TClass*);
   static void *new_xAODcLcLALFADataAuxContainer_v1(void *p = 0);
   static void *newArray_xAODcLcLALFADataAuxContainer_v1(Long_t size, void *p);
   static void delete_xAODcLcLALFADataAuxContainer_v1(void *p);
   static void deleteArray_xAODcLcLALFADataAuxContainer_v1(void *p);
   static void destruct_xAODcLcLALFADataAuxContainer_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ALFADataAuxContainer_v1*)
   {
      ::xAOD::ALFADataAuxContainer_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ALFADataAuxContainer_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ALFADataAuxContainer_v1", "xAODForward/versions/ALFADataAuxContainer_v1.h", 24,
                  typeid(::xAOD::ALFADataAuxContainer_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLALFADataAuxContainer_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ALFADataAuxContainer_v1) );
      instance.SetNew(&new_xAODcLcLALFADataAuxContainer_v1);
      instance.SetNewArray(&newArray_xAODcLcLALFADataAuxContainer_v1);
      instance.SetDelete(&delete_xAODcLcLALFADataAuxContainer_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLALFADataAuxContainer_v1);
      instance.SetDestructor(&destruct_xAODcLcLALFADataAuxContainer_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ALFADataAuxContainer_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ALFADataAuxContainer_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ALFADataAuxContainer_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLALFADataAuxContainer_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ALFADataAuxContainer_v1*)0x0)->GetClass();
      xAODcLcLALFADataAuxContainer_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLALFADataAuxContainer_v1_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","7D575485-A862-404F-85D0-D66BFB39D680");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLZdcModule_v1_Dictionary();
   static void xAODcLcLZdcModule_v1_TClassManip(TClass*);
   static void *new_xAODcLcLZdcModule_v1(void *p = 0);
   static void *newArray_xAODcLcLZdcModule_v1(Long_t size, void *p);
   static void delete_xAODcLcLZdcModule_v1(void *p);
   static void deleteArray_xAODcLcLZdcModule_v1(void *p);
   static void destruct_xAODcLcLZdcModule_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ZdcModule_v1*)
   {
      ::xAOD::ZdcModule_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ZdcModule_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ZdcModule_v1", "xAODForward/versions/ZdcModule_v1.h", 23,
                  typeid(::xAOD::ZdcModule_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLZdcModule_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ZdcModule_v1) );
      instance.SetNew(&new_xAODcLcLZdcModule_v1);
      instance.SetNewArray(&newArray_xAODcLcLZdcModule_v1);
      instance.SetDelete(&delete_xAODcLcLZdcModule_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLZdcModule_v1);
      instance.SetDestructor(&destruct_xAODcLcLZdcModule_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ZdcModule_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ZdcModule_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ZdcModule_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLZdcModule_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ZdcModule_v1*)0x0)->GetClass();
      xAODcLcLZdcModule_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLZdcModule_v1_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLZdcModule_v1gR_Dictionary();
   static void DataVectorlExAODcLcLZdcModule_v1gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLZdcModule_v1gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLZdcModule_v1gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLZdcModule_v1gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLZdcModule_v1gR(void *p);
   static void destruct_DataVectorlExAODcLcLZdcModule_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::ZdcModule_v1>*)
   {
      ::DataVector<xAOD::ZdcModule_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::ZdcModule_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::ZdcModule_v1>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::ZdcModule_v1>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLZdcModule_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::ZdcModule_v1>) );
      instance.SetNew(&new_DataVectorlExAODcLcLZdcModule_v1gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLZdcModule_v1gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLZdcModule_v1gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLZdcModule_v1gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLZdcModule_v1gR);

      ROOT::AddClassAlternate("DataVector<xAOD::ZdcModule_v1>","xAOD::ZdcModuleContainer_v1");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::ZdcModule_v1>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::ZdcModule_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::ZdcModule_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLZdcModule_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::ZdcModule_v1>*)0x0)->GetClass();
      DataVectorlExAODcLcLZdcModule_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLZdcModule_v1gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","C99119A0-E3AB-457F-85E7-EF0B44A3F5EB");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLZdcModuleAuxContainer_v1_Dictionary();
   static void xAODcLcLZdcModuleAuxContainer_v1_TClassManip(TClass*);
   static void *new_xAODcLcLZdcModuleAuxContainer_v1(void *p = 0);
   static void *newArray_xAODcLcLZdcModuleAuxContainer_v1(Long_t size, void *p);
   static void delete_xAODcLcLZdcModuleAuxContainer_v1(void *p);
   static void deleteArray_xAODcLcLZdcModuleAuxContainer_v1(void *p);
   static void destruct_xAODcLcLZdcModuleAuxContainer_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ZdcModuleAuxContainer_v1*)
   {
      ::xAOD::ZdcModuleAuxContainer_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ZdcModuleAuxContainer_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ZdcModuleAuxContainer_v1", "xAODForward/versions/ZdcModuleAuxContainer_v1.h", 26,
                  typeid(::xAOD::ZdcModuleAuxContainer_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLZdcModuleAuxContainer_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ZdcModuleAuxContainer_v1) );
      instance.SetNew(&new_xAODcLcLZdcModuleAuxContainer_v1);
      instance.SetNewArray(&newArray_xAODcLcLZdcModuleAuxContainer_v1);
      instance.SetDelete(&delete_xAODcLcLZdcModuleAuxContainer_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLZdcModuleAuxContainer_v1);
      instance.SetDestructor(&destruct_xAODcLcLZdcModuleAuxContainer_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ZdcModuleAuxContainer_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ZdcModuleAuxContainer_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ZdcModuleAuxContainer_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLZdcModuleAuxContainer_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ZdcModuleAuxContainer_v1*)0x0)->GetClass();
      xAODcLcLZdcModuleAuxContainer_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLZdcModuleAuxContainer_v1_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","72D723CD-1C67-49D2-9C70-5EE14C3B26A6");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLMBTSModule_v1_Dictionary();
   static void xAODcLcLMBTSModule_v1_TClassManip(TClass*);
   static void *new_xAODcLcLMBTSModule_v1(void *p = 0);
   static void *newArray_xAODcLcLMBTSModule_v1(Long_t size, void *p);
   static void delete_xAODcLcLMBTSModule_v1(void *p);
   static void deleteArray_xAODcLcLMBTSModule_v1(void *p);
   static void destruct_xAODcLcLMBTSModule_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::MBTSModule_v1*)
   {
      ::xAOD::MBTSModule_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::MBTSModule_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::MBTSModule_v1", "xAODForward/versions/MBTSModule_v1.h", 13,
                  typeid(::xAOD::MBTSModule_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLMBTSModule_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::MBTSModule_v1) );
      instance.SetNew(&new_xAODcLcLMBTSModule_v1);
      instance.SetNewArray(&newArray_xAODcLcLMBTSModule_v1);
      instance.SetDelete(&delete_xAODcLcLMBTSModule_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLMBTSModule_v1);
      instance.SetDestructor(&destruct_xAODcLcLMBTSModule_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::MBTSModule_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::MBTSModule_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::MBTSModule_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLMBTSModule_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::MBTSModule_v1*)0x0)->GetClass();
      xAODcLcLMBTSModule_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLMBTSModule_v1_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLMBTSModule_v1gR_Dictionary();
   static void DataVectorlExAODcLcLMBTSModule_v1gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLMBTSModule_v1gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLMBTSModule_v1gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLMBTSModule_v1gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLMBTSModule_v1gR(void *p);
   static void destruct_DataVectorlExAODcLcLMBTSModule_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::MBTSModule_v1>*)
   {
      ::DataVector<xAOD::MBTSModule_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::MBTSModule_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::MBTSModule_v1>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::MBTSModule_v1>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLMBTSModule_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::MBTSModule_v1>) );
      instance.SetNew(&new_DataVectorlExAODcLcLMBTSModule_v1gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLMBTSModule_v1gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLMBTSModule_v1gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLMBTSModule_v1gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLMBTSModule_v1gR);

      ROOT::AddClassAlternate("DataVector<xAOD::MBTSModule_v1>","xAOD::MBTSModuleContainer_v1");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::MBTSModule_v1>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::MBTSModule_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::MBTSModule_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLMBTSModule_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::MBTSModule_v1>*)0x0)->GetClass();
      DataVectorlExAODcLcLMBTSModule_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLMBTSModule_v1gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","661BBB15-2F8C-41FD-A1A8-F075C328DB5A");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLMBTSModuleAuxContainer_v1_Dictionary();
   static void xAODcLcLMBTSModuleAuxContainer_v1_TClassManip(TClass*);
   static void *new_xAODcLcLMBTSModuleAuxContainer_v1(void *p = 0);
   static void *newArray_xAODcLcLMBTSModuleAuxContainer_v1(Long_t size, void *p);
   static void delete_xAODcLcLMBTSModuleAuxContainer_v1(void *p);
   static void deleteArray_xAODcLcLMBTSModuleAuxContainer_v1(void *p);
   static void destruct_xAODcLcLMBTSModuleAuxContainer_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::MBTSModuleAuxContainer_v1*)
   {
      ::xAOD::MBTSModuleAuxContainer_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::MBTSModuleAuxContainer_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::MBTSModuleAuxContainer_v1", "xAODForward/versions/MBTSModuleAuxContainer_v1.h", 18,
                  typeid(::xAOD::MBTSModuleAuxContainer_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLMBTSModuleAuxContainer_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::MBTSModuleAuxContainer_v1) );
      instance.SetNew(&new_xAODcLcLMBTSModuleAuxContainer_v1);
      instance.SetNewArray(&newArray_xAODcLcLMBTSModuleAuxContainer_v1);
      instance.SetDelete(&delete_xAODcLcLMBTSModuleAuxContainer_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLMBTSModuleAuxContainer_v1);
      instance.SetDestructor(&destruct_xAODcLcLMBTSModuleAuxContainer_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::MBTSModuleAuxContainer_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::MBTSModuleAuxContainer_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::MBTSModuleAuxContainer_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLMBTSModuleAuxContainer_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::MBTSModuleAuxContainer_v1*)0x0)->GetClass();
      xAODcLcLMBTSModuleAuxContainer_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLMBTSModuleAuxContainer_v1_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","9D3409D5-8503-4994-BE9B-41F412D4E5A1");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLForwardEventInfo_v1_Dictionary();
   static void xAODcLcLForwardEventInfo_v1_TClassManip(TClass*);
   static void *new_xAODcLcLForwardEventInfo_v1(void *p = 0);
   static void *newArray_xAODcLcLForwardEventInfo_v1(Long_t size, void *p);
   static void delete_xAODcLcLForwardEventInfo_v1(void *p);
   static void deleteArray_xAODcLcLForwardEventInfo_v1(void *p);
   static void destruct_xAODcLcLForwardEventInfo_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ForwardEventInfo_v1*)
   {
      ::xAOD::ForwardEventInfo_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ForwardEventInfo_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ForwardEventInfo_v1", "xAODForward/versions/ForwardEventInfo_v1.h", 12,
                  typeid(::xAOD::ForwardEventInfo_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLForwardEventInfo_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ForwardEventInfo_v1) );
      instance.SetNew(&new_xAODcLcLForwardEventInfo_v1);
      instance.SetNewArray(&newArray_xAODcLcLForwardEventInfo_v1);
      instance.SetDelete(&delete_xAODcLcLForwardEventInfo_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLForwardEventInfo_v1);
      instance.SetDestructor(&destruct_xAODcLcLForwardEventInfo_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ForwardEventInfo_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ForwardEventInfo_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ForwardEventInfo_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLForwardEventInfo_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ForwardEventInfo_v1*)0x0)->GetClass();
      xAODcLcLForwardEventInfo_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLForwardEventInfo_v1_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataVectorlExAODcLcLForwardEventInfo_v1gR_Dictionary();
   static void DataVectorlExAODcLcLForwardEventInfo_v1gR_TClassManip(TClass*);
   static void *new_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p = 0);
   static void *newArray_DataVectorlExAODcLcLForwardEventInfo_v1gR(Long_t size, void *p);
   static void delete_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p);
   static void deleteArray_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p);
   static void destruct_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataVector<xAOD::ForwardEventInfo_v1>*)
   {
      ::DataVector<xAOD::ForwardEventInfo_v1> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataVector<xAOD::ForwardEventInfo_v1>));
      static ::ROOT::TGenericClassInfo 
         instance("DataVector<xAOD::ForwardEventInfo_v1>", "AthContainers/DataVector.h", 1920,
                  typeid(::DataVector<xAOD::ForwardEventInfo_v1>), DefineBehavior(ptr, ptr),
                  &DataVectorlExAODcLcLForwardEventInfo_v1gR_Dictionary, isa_proxy, 0,
                  sizeof(::DataVector<xAOD::ForwardEventInfo_v1>) );
      instance.SetNew(&new_DataVectorlExAODcLcLForwardEventInfo_v1gR);
      instance.SetNewArray(&newArray_DataVectorlExAODcLcLForwardEventInfo_v1gR);
      instance.SetDelete(&delete_DataVectorlExAODcLcLForwardEventInfo_v1gR);
      instance.SetDeleteArray(&deleteArray_DataVectorlExAODcLcLForwardEventInfo_v1gR);
      instance.SetDestructor(&destruct_DataVectorlExAODcLcLForwardEventInfo_v1gR);

      ROOT::AddClassAlternate("DataVector<xAOD::ForwardEventInfo_v1>","xAOD::ForwardEventInfoContainer_v1");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataVector<xAOD::ForwardEventInfo_v1>*)
   {
      return GenerateInitInstanceLocal((::DataVector<xAOD::ForwardEventInfo_v1>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataVector<xAOD::ForwardEventInfo_v1>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataVectorlExAODcLcLForwardEventInfo_v1gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataVector<xAOD::ForwardEventInfo_v1>*)0x0)->GetClass();
      DataVectorlExAODcLcLForwardEventInfo_v1gR_TClassManip(theClass);
   return theClass;
   }

   static void DataVectorlExAODcLcLForwardEventInfo_v1gR_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","AAB8E87D-FEFB-481F-BA4C-AB35852A8026");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *xAODcLcLForwardEventInfoAuxContainer_v1_Dictionary();
   static void xAODcLcLForwardEventInfoAuxContainer_v1_TClassManip(TClass*);
   static void *new_xAODcLcLForwardEventInfoAuxContainer_v1(void *p = 0);
   static void *newArray_xAODcLcLForwardEventInfoAuxContainer_v1(Long_t size, void *p);
   static void delete_xAODcLcLForwardEventInfoAuxContainer_v1(void *p);
   static void deleteArray_xAODcLcLForwardEventInfoAuxContainer_v1(void *p);
   static void destruct_xAODcLcLForwardEventInfoAuxContainer_v1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::xAOD::ForwardEventInfoAuxContainer_v1*)
   {
      ::xAOD::ForwardEventInfoAuxContainer_v1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::xAOD::ForwardEventInfoAuxContainer_v1));
      static ::ROOT::TGenericClassInfo 
         instance("xAOD::ForwardEventInfoAuxContainer_v1", "xAODForward/versions/ForwardEventInfoAuxContainer_v1.h", 18,
                  typeid(::xAOD::ForwardEventInfoAuxContainer_v1), DefineBehavior(ptr, ptr),
                  &xAODcLcLForwardEventInfoAuxContainer_v1_Dictionary, isa_proxy, 0,
                  sizeof(::xAOD::ForwardEventInfoAuxContainer_v1) );
      instance.SetNew(&new_xAODcLcLForwardEventInfoAuxContainer_v1);
      instance.SetNewArray(&newArray_xAODcLcLForwardEventInfoAuxContainer_v1);
      instance.SetDelete(&delete_xAODcLcLForwardEventInfoAuxContainer_v1);
      instance.SetDeleteArray(&deleteArray_xAODcLcLForwardEventInfoAuxContainer_v1);
      instance.SetDestructor(&destruct_xAODcLcLForwardEventInfoAuxContainer_v1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::xAOD::ForwardEventInfoAuxContainer_v1*)
   {
      return GenerateInitInstanceLocal((::xAOD::ForwardEventInfoAuxContainer_v1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::xAOD::ForwardEventInfoAuxContainer_v1*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *xAODcLcLForwardEventInfoAuxContainer_v1_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::xAOD::ForwardEventInfoAuxContainer_v1*)0x0)->GetClass();
      xAODcLcLForwardEventInfoAuxContainer_v1_TClassManip(theClass);
   return theClass;
   }

   static void xAODcLcLForwardEventInfoAuxContainer_v1_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("id","1795DED0-A289-4173-9BA9-E8A28D7FB2BE");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary();
   static void DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(TClass*);
   static void *new_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p = 0);
   static void *newArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(Long_t size, void *p);
   static void delete_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);
   static void deleteArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);
   static void destruct_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<DataVector<xAOD::ALFAData_v1> >*)
   {
      ::DataLink<DataVector<xAOD::ALFAData_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<DataVector<xAOD::ALFAData_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<DataVector<xAOD::ALFAData_v1> >", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<DataVector<xAOD::ALFAData_v1> >), DefineBehavior(ptr, ptr),
                  &DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<DataVector<xAOD::ALFAData_v1> >) );
      instance.SetNew(&new_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetNewArray(&newArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDelete(&delete_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDestructor(&destruct_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);

      ROOT::AddClassAlternate("DataLink<DataVector<xAOD::ALFAData_v1> >","DataLink<xAOD::ALFADataContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<DataVector<xAOD::ALFAData_v1> >*)
   {
      return GenerateInitInstanceLocal((::DataLink<DataVector<xAOD::ALFAData_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ALFAData_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ALFAData_v1> >*)0x0)->GetClass();
      DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::ALFAData_v1> >*)
   {
      ::ElementLink<DataVector<xAOD::ALFAData_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::ALFAData_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::ALFAData_v1> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::ALFAData_v1> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::ALFAData_v1> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::ALFAData_v1> >","ElementLink<xAOD::ALFADataContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::ALFAData_v1> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::ALFAData_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ALFAData_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ALFAData_v1> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary();
   static void DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(TClass*);
   static void *new_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p = 0);
   static void *newArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(Long_t size, void *p);
   static void delete_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);
   static void deleteArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);
   static void destruct_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<DataVector<xAOD::ZdcModule_v1> >*)
   {
      ::DataLink<DataVector<xAOD::ZdcModule_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<DataVector<xAOD::ZdcModule_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<DataVector<xAOD::ZdcModule_v1> >", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<DataVector<xAOD::ZdcModule_v1> >), DefineBehavior(ptr, ptr),
                  &DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<DataVector<xAOD::ZdcModule_v1> >) );
      instance.SetNew(&new_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetNewArray(&newArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDelete(&delete_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDestructor(&destruct_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);

      ROOT::AddClassAlternate("DataLink<DataVector<xAOD::ZdcModule_v1> >","DataLink<xAOD::ZdcModuleContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<DataVector<xAOD::ZdcModule_v1> >*)
   {
      return GenerateInitInstanceLocal((::DataLink<DataVector<xAOD::ZdcModule_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ZdcModule_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ZdcModule_v1> >*)0x0)->GetClass();
      DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)
   {
      ::ElementLink<DataVector<xAOD::ZdcModule_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::ZdcModule_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::ZdcModule_v1> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::ZdcModule_v1> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::ZdcModule_v1> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::ZdcModule_v1> >","ElementLink<xAOD::ZdcModuleContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)
   {
      ::ElementLink<DataVector<xAOD::TriggerTower_v2> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::TriggerTower_v2> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::TriggerTower_v2> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::TriggerTower_v2> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::TriggerTower_v2> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::TriggerTower_v2> >","ElementLink<xAOD::TriggerTowerContainer_v2>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary();
   static void DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(TClass*);
   static void *new_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p = 0);
   static void *newArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(Long_t size, void *p);
   static void delete_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);
   static void deleteArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);
   static void destruct_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<DataVector<xAOD::MBTSModule_v1> >*)
   {
      ::DataLink<DataVector<xAOD::MBTSModule_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<DataVector<xAOD::MBTSModule_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<DataVector<xAOD::MBTSModule_v1> >", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<DataVector<xAOD::MBTSModule_v1> >), DefineBehavior(ptr, ptr),
                  &DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<DataVector<xAOD::MBTSModule_v1> >) );
      instance.SetNew(&new_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetNewArray(&newArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDelete(&delete_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDestructor(&destruct_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);

      ROOT::AddClassAlternate("DataLink<DataVector<xAOD::MBTSModule_v1> >","DataLink<xAOD::MBTSModuleContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<DataVector<xAOD::MBTSModule_v1> >*)
   {
      return GenerateInitInstanceLocal((::DataLink<DataVector<xAOD::MBTSModule_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::MBTSModule_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::MBTSModule_v1> >*)0x0)->GetClass();
      DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)
   {
      ::ElementLink<DataVector<xAOD::MBTSModule_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::MBTSModule_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::MBTSModule_v1> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::MBTSModule_v1> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::MBTSModule_v1> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::MBTSModule_v1> >","ElementLink<xAOD::MBTSModuleContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary();
   static void DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(TClass*);
   static void *new_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p = 0);
   static void *newArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(Long_t size, void *p);
   static void delete_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);
   static void deleteArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);
   static void destruct_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)
   {
      ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("DataLink<DataVector<xAOD::ForwardEventInfo_v1> >", "AthLinks/DataLink.h", 37,
                  typeid(::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >), DefineBehavior(ptr, ptr),
                  &DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >) );
      instance.SetNew(&new_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetNewArray(&newArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDelete(&delete_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDestructor(&destruct_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);

      ROOT::AddClassAlternate("DataLink<DataVector<xAOD::ForwardEventInfo_v1> >","DataLink<xAOD::ForwardEventInfoContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)
   {
      return GenerateInitInstanceLocal((::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0x0)->GetClass();
      DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary();
   static void ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(TClass*);
   static void *new_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p = 0);
   static void *newArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(Long_t size, void *p);
   static void delete_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);
   static void destruct_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)
   {
      ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >));
      static ::ROOT::TGenericClassInfo 
         instance("ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >", "AthLinks/ElementLink.h", 39,
                  typeid(::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >), DefineBehavior(ptr, ptr),
                  &ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >) );
      instance.SetNew(&new_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetNewArray(&newArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDelete(&delete_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDeleteArray(&deleteArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);
      instance.SetDestructor(&destruct_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR);

      ROOT::AddClassAlternate("ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >","ElementLink<xAOD::ForwardEventInfoContainer_v1>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)
   {
      return GenerateInitInstanceLocal((::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)0x0)->GetClass();
      ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLALFAData_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ALFAData_v1 : new ::xAOD::ALFAData_v1;
   }
   static void *newArray_xAODcLcLALFAData_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ALFAData_v1[nElements] : new ::xAOD::ALFAData_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLALFAData_v1(void *p) {
      delete ((::xAOD::ALFAData_v1*)p);
   }
   static void deleteArray_xAODcLcLALFAData_v1(void *p) {
      delete [] ((::xAOD::ALFAData_v1*)p);
   }
   static void destruct_xAODcLcLALFAData_v1(void *p) {
      typedef ::xAOD::ALFAData_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ALFAData_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLALFAData_v1gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::ALFAData_v1> : new ::DataVector<xAOD::ALFAData_v1>;
   }
   static void *newArray_DataVectorlExAODcLcLALFAData_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::ALFAData_v1>[nElements] : new ::DataVector<xAOD::ALFAData_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLALFAData_v1gR(void *p) {
      delete ((::DataVector<xAOD::ALFAData_v1>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLALFAData_v1gR(void *p) {
      delete [] ((::DataVector<xAOD::ALFAData_v1>*)p);
   }
   static void destruct_DataVectorlExAODcLcLALFAData_v1gR(void *p) {
      typedef ::DataVector<xAOD::ALFAData_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::ALFAData_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLALFADataAuxContainer_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ALFADataAuxContainer_v1 : new ::xAOD::ALFADataAuxContainer_v1;
   }
   static void *newArray_xAODcLcLALFADataAuxContainer_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ALFADataAuxContainer_v1[nElements] : new ::xAOD::ALFADataAuxContainer_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLALFADataAuxContainer_v1(void *p) {
      delete ((::xAOD::ALFADataAuxContainer_v1*)p);
   }
   static void deleteArray_xAODcLcLALFADataAuxContainer_v1(void *p) {
      delete [] ((::xAOD::ALFADataAuxContainer_v1*)p);
   }
   static void destruct_xAODcLcLALFADataAuxContainer_v1(void *p) {
      typedef ::xAOD::ALFADataAuxContainer_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ALFADataAuxContainer_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLZdcModule_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ZdcModule_v1 : new ::xAOD::ZdcModule_v1;
   }
   static void *newArray_xAODcLcLZdcModule_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ZdcModule_v1[nElements] : new ::xAOD::ZdcModule_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLZdcModule_v1(void *p) {
      delete ((::xAOD::ZdcModule_v1*)p);
   }
   static void deleteArray_xAODcLcLZdcModule_v1(void *p) {
      delete [] ((::xAOD::ZdcModule_v1*)p);
   }
   static void destruct_xAODcLcLZdcModule_v1(void *p) {
      typedef ::xAOD::ZdcModule_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ZdcModule_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLZdcModule_v1gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::ZdcModule_v1> : new ::DataVector<xAOD::ZdcModule_v1>;
   }
   static void *newArray_DataVectorlExAODcLcLZdcModule_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::ZdcModule_v1>[nElements] : new ::DataVector<xAOD::ZdcModule_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLZdcModule_v1gR(void *p) {
      delete ((::DataVector<xAOD::ZdcModule_v1>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLZdcModule_v1gR(void *p) {
      delete [] ((::DataVector<xAOD::ZdcModule_v1>*)p);
   }
   static void destruct_DataVectorlExAODcLcLZdcModule_v1gR(void *p) {
      typedef ::DataVector<xAOD::ZdcModule_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::ZdcModule_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLZdcModuleAuxContainer_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ZdcModuleAuxContainer_v1 : new ::xAOD::ZdcModuleAuxContainer_v1;
   }
   static void *newArray_xAODcLcLZdcModuleAuxContainer_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ZdcModuleAuxContainer_v1[nElements] : new ::xAOD::ZdcModuleAuxContainer_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLZdcModuleAuxContainer_v1(void *p) {
      delete ((::xAOD::ZdcModuleAuxContainer_v1*)p);
   }
   static void deleteArray_xAODcLcLZdcModuleAuxContainer_v1(void *p) {
      delete [] ((::xAOD::ZdcModuleAuxContainer_v1*)p);
   }
   static void destruct_xAODcLcLZdcModuleAuxContainer_v1(void *p) {
      typedef ::xAOD::ZdcModuleAuxContainer_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ZdcModuleAuxContainer_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLMBTSModule_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::MBTSModule_v1 : new ::xAOD::MBTSModule_v1;
   }
   static void *newArray_xAODcLcLMBTSModule_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::MBTSModule_v1[nElements] : new ::xAOD::MBTSModule_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLMBTSModule_v1(void *p) {
      delete ((::xAOD::MBTSModule_v1*)p);
   }
   static void deleteArray_xAODcLcLMBTSModule_v1(void *p) {
      delete [] ((::xAOD::MBTSModule_v1*)p);
   }
   static void destruct_xAODcLcLMBTSModule_v1(void *p) {
      typedef ::xAOD::MBTSModule_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::MBTSModule_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLMBTSModule_v1gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::MBTSModule_v1> : new ::DataVector<xAOD::MBTSModule_v1>;
   }
   static void *newArray_DataVectorlExAODcLcLMBTSModule_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::MBTSModule_v1>[nElements] : new ::DataVector<xAOD::MBTSModule_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLMBTSModule_v1gR(void *p) {
      delete ((::DataVector<xAOD::MBTSModule_v1>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLMBTSModule_v1gR(void *p) {
      delete [] ((::DataVector<xAOD::MBTSModule_v1>*)p);
   }
   static void destruct_DataVectorlExAODcLcLMBTSModule_v1gR(void *p) {
      typedef ::DataVector<xAOD::MBTSModule_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::MBTSModule_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLMBTSModuleAuxContainer_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::MBTSModuleAuxContainer_v1 : new ::xAOD::MBTSModuleAuxContainer_v1;
   }
   static void *newArray_xAODcLcLMBTSModuleAuxContainer_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::MBTSModuleAuxContainer_v1[nElements] : new ::xAOD::MBTSModuleAuxContainer_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLMBTSModuleAuxContainer_v1(void *p) {
      delete ((::xAOD::MBTSModuleAuxContainer_v1*)p);
   }
   static void deleteArray_xAODcLcLMBTSModuleAuxContainer_v1(void *p) {
      delete [] ((::xAOD::MBTSModuleAuxContainer_v1*)p);
   }
   static void destruct_xAODcLcLMBTSModuleAuxContainer_v1(void *p) {
      typedef ::xAOD::MBTSModuleAuxContainer_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::MBTSModuleAuxContainer_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLForwardEventInfo_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ForwardEventInfo_v1 : new ::xAOD::ForwardEventInfo_v1;
   }
   static void *newArray_xAODcLcLForwardEventInfo_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ForwardEventInfo_v1[nElements] : new ::xAOD::ForwardEventInfo_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLForwardEventInfo_v1(void *p) {
      delete ((::xAOD::ForwardEventInfo_v1*)p);
   }
   static void deleteArray_xAODcLcLForwardEventInfo_v1(void *p) {
      delete [] ((::xAOD::ForwardEventInfo_v1*)p);
   }
   static void destruct_xAODcLcLForwardEventInfo_v1(void *p) {
      typedef ::xAOD::ForwardEventInfo_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ForwardEventInfo_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p) {
      return  p ? new(p) ::DataVector<xAOD::ForwardEventInfo_v1> : new ::DataVector<xAOD::ForwardEventInfo_v1>;
   }
   static void *newArray_DataVectorlExAODcLcLForwardEventInfo_v1gR(Long_t nElements, void *p) {
      return p ? new(p) ::DataVector<xAOD::ForwardEventInfo_v1>[nElements] : new ::DataVector<xAOD::ForwardEventInfo_v1>[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p) {
      delete ((::DataVector<xAOD::ForwardEventInfo_v1>*)p);
   }
   static void deleteArray_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p) {
      delete [] ((::DataVector<xAOD::ForwardEventInfo_v1>*)p);
   }
   static void destruct_DataVectorlExAODcLcLForwardEventInfo_v1gR(void *p) {
      typedef ::DataVector<xAOD::ForwardEventInfo_v1> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataVector<xAOD::ForwardEventInfo_v1>

namespace ROOT {
   // Wrappers around operator new
   static void *new_xAODcLcLForwardEventInfoAuxContainer_v1(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ForwardEventInfoAuxContainer_v1 : new ::xAOD::ForwardEventInfoAuxContainer_v1;
   }
   static void *newArray_xAODcLcLForwardEventInfoAuxContainer_v1(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::xAOD::ForwardEventInfoAuxContainer_v1[nElements] : new ::xAOD::ForwardEventInfoAuxContainer_v1[nElements];
   }
   // Wrapper around operator delete
   static void delete_xAODcLcLForwardEventInfoAuxContainer_v1(void *p) {
      delete ((::xAOD::ForwardEventInfoAuxContainer_v1*)p);
   }
   static void deleteArray_xAODcLcLForwardEventInfoAuxContainer_v1(void *p) {
      delete [] ((::xAOD::ForwardEventInfoAuxContainer_v1*)p);
   }
   static void destruct_xAODcLcLForwardEventInfoAuxContainer_v1(void *p) {
      typedef ::xAOD::ForwardEventInfoAuxContainer_v1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::xAOD::ForwardEventInfoAuxContainer_v1

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      return  p ? new(p) ::DataLink<DataVector<xAOD::ALFAData_v1> > : new ::DataLink<DataVector<xAOD::ALFAData_v1> >;
   }
   static void *newArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<DataVector<xAOD::ALFAData_v1> >[nElements] : new ::DataLink<DataVector<xAOD::ALFAData_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      delete ((::DataLink<DataVector<xAOD::ALFAData_v1> >*)p);
   }
   static void deleteArray_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      delete [] ((::DataLink<DataVector<xAOD::ALFAData_v1> >*)p);
   }
   static void destruct_DataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      typedef ::DataLink<DataVector<xAOD::ALFAData_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<DataVector<xAOD::ALFAData_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::ALFAData_v1> > : new ::ElementLink<DataVector<xAOD::ALFAData_v1> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::ALFAData_v1> >[nElements] : new ::ElementLink<DataVector<xAOD::ALFAData_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::ALFAData_v1> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::ALFAData_v1> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::ALFAData_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::ALFAData_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      return  p ? new(p) ::DataLink<DataVector<xAOD::ZdcModule_v1> > : new ::DataLink<DataVector<xAOD::ZdcModule_v1> >;
   }
   static void *newArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<DataVector<xAOD::ZdcModule_v1> >[nElements] : new ::DataLink<DataVector<xAOD::ZdcModule_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      delete ((::DataLink<DataVector<xAOD::ZdcModule_v1> >*)p);
   }
   static void deleteArray_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      delete [] ((::DataLink<DataVector<xAOD::ZdcModule_v1> >*)p);
   }
   static void destruct_DataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      typedef ::DataLink<DataVector<xAOD::ZdcModule_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<DataVector<xAOD::ZdcModule_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::ZdcModule_v1> > : new ::ElementLink<DataVector<xAOD::ZdcModule_v1> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::ZdcModule_v1> >[nElements] : new ::ElementLink<DataVector<xAOD::ZdcModule_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::ZdcModule_v1> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::ZdcModule_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::ZdcModule_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::TriggerTower_v2> > : new ::ElementLink<DataVector<xAOD::TriggerTower_v2> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::TriggerTower_v2> >[nElements] : new ::ElementLink<DataVector<xAOD::TriggerTower_v2> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::TriggerTower_v2> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::TriggerTower_v2> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::TriggerTower_v2> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      return  p ? new(p) ::DataLink<DataVector<xAOD::MBTSModule_v1> > : new ::DataLink<DataVector<xAOD::MBTSModule_v1> >;
   }
   static void *newArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<DataVector<xAOD::MBTSModule_v1> >[nElements] : new ::DataLink<DataVector<xAOD::MBTSModule_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      delete ((::DataLink<DataVector<xAOD::MBTSModule_v1> >*)p);
   }
   static void deleteArray_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      delete [] ((::DataLink<DataVector<xAOD::MBTSModule_v1> >*)p);
   }
   static void destruct_DataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      typedef ::DataLink<DataVector<xAOD::MBTSModule_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<DataVector<xAOD::MBTSModule_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::MBTSModule_v1> > : new ::ElementLink<DataVector<xAOD::MBTSModule_v1> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::MBTSModule_v1> >[nElements] : new ::ElementLink<DataVector<xAOD::MBTSModule_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::MBTSModule_v1> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::MBTSModule_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::MBTSModule_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      return  p ? new(p) ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> > : new ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >;
   }
   static void *newArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >[nElements] : new ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      delete ((::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)p);
   }
   static void deleteArray_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      delete [] ((::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >*)p);
   }
   static void destruct_DataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      typedef ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DataLink<DataVector<xAOD::ForwardEventInfo_v1> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      return  p ? new(p) ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > : new ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >;
   }
   static void *newArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >[nElements] : new ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      delete ((::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)p);
   }
   static void deleteArray_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      delete [] ((::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >*)p);
   }
   static void destruct_ElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgR(void *p) {
      typedef ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >

namespace ROOT {
   static TClass *vectorlEvectorlEshortgRsPgR_Dictionary();
   static void vectorlEvectorlEshortgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEshortgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEshortgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEshortgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEshortgRsPgR(void *p);
   static void destruct_vectorlEvectorlEshortgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<short> >*)
   {
      vector<vector<short> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<short> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<short> >", -2, "vector", 210,
                  typeid(vector<vector<short> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEshortgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<short> >) );
      instance.SetNew(&new_vectorlEvectorlEshortgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEshortgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEshortgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEshortgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEshortgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<short> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<short> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEshortgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<short> >*)0x0)->GetClass();
      vectorlEvectorlEshortgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEshortgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEshortgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<short> > : new vector<vector<short> >;
   }
   static void *newArray_vectorlEvectorlEshortgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<short> >[nElements] : new vector<vector<short> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEshortgRsPgR(void *p) {
      delete ((vector<vector<short> >*)p);
   }
   static void deleteArray_vectorlEvectorlEshortgRsPgR(void *p) {
      delete [] ((vector<vector<short> >*)p);
   }
   static void destruct_vectorlEvectorlEshortgRsPgR(void *p) {
      typedef vector<vector<short> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<short> >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > > : new vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > > : new vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > > : new vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >

namespace ROOT {
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >*)
   {
      vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >", -2, "vector", 210,
                  typeid(vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >) );
      instance.SetNew(&new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >*)0x0)->GetClass();
      vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > > : new vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >;
   }
   static void *newArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >[nElements] : new vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p) {
      delete ((vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >*)p);
   }
   static void deleteArray_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >*)p);
   }
   static void destruct_vectorlEvectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgRsPgR(void *p) {
      typedef vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >

namespace ROOT {
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = 0);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 210,
                  typeid(vector<short>), DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<short>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<short>*)0x0)->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete ((vector<short>*)p);
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] ((vector<short>*)p);
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<short>

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >*)
   {
      vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > : new vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >[nElements] : new vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >*)
   {
      vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > > : new vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >[nElements] : new vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLTriggerTower_v2gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >*)
   {
      vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > : new vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >[nElements] : new vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)
   {
      vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > : new vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >[nElements] : new vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >

namespace ROOT {
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary();
   static void vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >*)
   {
      vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >", -2, "vector", 210,
                  typeid(vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >) );
      instance.SetNew(&new_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >*)0x0)->GetClass();
      vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > : new vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >;
   }
   static void *newArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >[nElements] : new vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      delete ((vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >*)p);
   }
   static void deleteArray_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >*)p);
   }
   static void destruct_vectorlEElementLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      typedef vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >

namespace ROOT {
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary();
   static void vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >*)
   {
      vector<DataLink<DataVector<xAOD::ZdcModule_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >", -2, "vector", 210,
                  typeid(vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >) );
      instance.SetNew(&new_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<DataVector<xAOD::ZdcModule_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >*)0x0)->GetClass();
      vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ZdcModule_v1> > > : new vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >;
   }
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >[nElements] : new vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      delete ((vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >*)p);
   }
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >*)p);
   }
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLZdcModule_v1gRsPgRsPgR(void *p) {
      typedef vector<DataLink<DataVector<xAOD::ZdcModule_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >

namespace ROOT {
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary();
   static void vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >*)
   {
      vector<DataLink<DataVector<xAOD::MBTSModule_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >", -2, "vector", 210,
                  typeid(vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >) );
      instance.SetNew(&new_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<DataVector<xAOD::MBTSModule_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >*)0x0)->GetClass();
      vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::MBTSModule_v1> > > : new vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >;
   }
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >[nElements] : new vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      delete ((vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >*)p);
   }
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >*)p);
   }
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLMBTSModule_v1gRsPgRsPgR(void *p) {
      typedef vector<DataLink<DataVector<xAOD::MBTSModule_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >

namespace ROOT {
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary();
   static void vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)
   {
      vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >", -2, "vector", 210,
                  typeid(vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >) );
      instance.SetNew(&new_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)0x0)->GetClass();
      vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > > : new vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >;
   }
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >[nElements] : new vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      delete ((vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)p);
   }
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >*)p);
   }
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLForwardEventInfo_v1gRsPgRsPgR(void *p) {
      typedef vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >

namespace ROOT {
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary();
   static void vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DataLink<DataVector<xAOD::ALFAData_v1> > >*)
   {
      vector<DataLink<DataVector<xAOD::ALFAData_v1> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DataLink<DataVector<xAOD::ALFAData_v1> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DataLink<DataVector<xAOD::ALFAData_v1> > >", -2, "vector", 210,
                  typeid(vector<DataLink<DataVector<xAOD::ALFAData_v1> > >), DefineBehavior(ptr, ptr),
                  &vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DataLink<DataVector<xAOD::ALFAData_v1> > >) );
      instance.SetNew(&new_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DataLink<DataVector<xAOD::ALFAData_v1> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ALFAData_v1> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DataLink<DataVector<xAOD::ALFAData_v1> > >*)0x0)->GetClass();
      vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ALFAData_v1> > > : new vector<DataLink<DataVector<xAOD::ALFAData_v1> > >;
   }
   static void *newArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<DataLink<DataVector<xAOD::ALFAData_v1> > >[nElements] : new vector<DataLink<DataVector<xAOD::ALFAData_v1> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      delete ((vector<DataLink<DataVector<xAOD::ALFAData_v1> > >*)p);
   }
   static void deleteArray_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      delete [] ((vector<DataLink<DataVector<xAOD::ALFAData_v1> > >*)p);
   }
   static void destruct_vectorlEDataLinklEDataVectorlExAODcLcLALFAData_v1gRsPgRsPgR(void *p) {
      typedef vector<DataLink<DataVector<xAOD::ALFAData_v1> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DataLink<DataVector<xAOD::ALFAData_v1> > >

namespace {
  void TriggerDictionaryInitialization_xAODForward_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/work/m/mizhou/RUN_FB/xAODForward/Root",
"/afs/cern.ch/work/m/mizhou/RUN_FB/xAODForward",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/work/m/mizhou/RUN_FB/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.12-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/work/m/mizhou/RUN_FB/xAODForward/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/ALFADataContainer.h")))  ALFAData_v1;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@7D575485-A862-404F-85D0-D66BFB39D680)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODForward/ALFADataAuxContainer.h")))  ALFADataAuxContainer_v1;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/ZdcModuleContainer.h")))  ZdcModule_v1;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@72D723CD-1C67-49D2-9C70-5EE14C3B26A6)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODForward/ZdcModuleAuxContainer.h")))  ZdcModuleAuxContainer_v1;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/MBTSModuleContainer.h")))  MBTSModule_v1;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@9D3409D5-8503-4994-BE9B-41F412D4E5A1)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODForward/MBTSModuleAuxContainer.h")))  MBTSModuleAuxContainer_v1;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/ForwardEventInfoContainer.h")))  ForwardEventInfo_v1;}
namespace xAOD{class __attribute__((annotate(R"ATTRDUMP(id@@@1795DED0-A289-4173-9BA9-E8A28D7FB2BE)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$xAODForward/ForwardEventInfoAuxContainer.h")))  ForwardEventInfoAuxContainer_v1;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/ZdcModuleContainer.h")))  TriggerTower_v2;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$xAODForward/ZdcModuleContainer.h")))  IParticle;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
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
  #define ROOTCORE_PACKAGE "xAODForward"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Dear emacs, this is -*- c++ -*-
// $Id: xAODForwardDict.h 708124 2015-11-16 13:24:22Z steinber $
#ifndef XAODFORWARD_XAODFORWARDDICT_H
#define XAODFORWARD_XAODFORWARDDICT_H

// STL include(s):
#include <vector>

// EDM include(s):
#include "AthLinks/DataLink.h"
#include "AthLinks/ElementLink.h"

// Local include(s):
#include "xAODForward/ALFADataContainer.h"
#include "xAODForward/ALFADataAuxContainer.h"
#include "xAODForward/versions/ALFADataContainer_v1.h"
#include "xAODForward/versions/ALFADataAuxContainer_v1.h"
#include "xAODForward/versions/ALFAData_v1.h"

#include "xAODForward/ZdcModuleContainer.h"
#include "xAODForward/ZdcModuleAuxContainer.h"
#include "xAODForward/versions/ZdcModuleContainer_v1.h"
#include "xAODForward/versions/ZdcModuleAuxContainer_v1.h"
#include "xAODForward/versions/ZdcModule_v1.h"

#include "xAODForward/MBTSModuleContainer.h"
#include "xAODForward/MBTSModuleAuxContainer.h"
#include "xAODForward/versions/MBTSModuleContainer_v1.h"
#include "xAODForward/versions/MBTSModuleAuxContainer_v1.h"
#include "xAODForward/versions/MBTSModule_v1.h"

#include "xAODForward/ForwardEventInfoContainer.h"
#include "xAODForward/ForwardEventInfoAuxContainer.h"
#include "xAODForward/versions/ForwardEventInfoContainer_v1.h"
#include "xAODForward/versions/ForwardEventInfoAuxContainer_v1.h"
#include "xAODForward/versions/ForwardEventInfo_v1.h"
namespace{
   struct GCCXML_DUMMY_INSTANTIATION_ALFA_XAOD {

      xAOD::ALFADataContainer_v1 alfa_c1;

      DataLink<xAOD::ALFADataContainer_v1> alfa_l1;
      std::vector<DataLink<xAOD::ALFADataContainer_v1> > alfa_l2;

      ElementLink<xAOD::ALFADataContainer_v1> alfa_l3;
      std::vector<ElementLink<xAOD::ALFADataContainer_v1> > alfa_l4;
      std::vector<std::vector<ElementLink<xAOD::ALFADataContainer_v1> > >
         alfa_l5;
     //   };

     //struct GCCXML_DUMMY_INSTANTIATION_ZDC_XAOD {

      xAOD::ZdcModuleContainer_v1 zdc_c1;

        DataLink<xAOD::ZdcModuleContainer_v1> zdc_l1;
      std::vector<DataLink<xAOD::ZdcModuleContainer_v1> > zdc_l2;

      ElementLink<xAOD::ZdcModuleContainer_v1> zdc_l3;
      std::vector<ElementLink<xAOD::ZdcModuleContainer_v1> > zdc_l4;
      std::vector<std::vector<ElementLink<xAOD::ZdcModuleContainer_v1> > > zdc_l5;

     //must also instantiate the element links used by any aux containers
     ElementLink< xAOD::TriggerTowerContainer > zdc_l6;
     std::vector< ElementLink< xAOD::TriggerTowerContainer > > zdc_l7;
     std::vector< std::vector<short> > zdc_l8;

     //and for mbtsmodule
     xAOD::MBTSModuleContainer_v1 mbts_c1;

     DataLink<xAOD::MBTSModuleContainer_v1> mbts_l1;
     std::vector<DataLink<xAOD::MBTSModuleContainer_v1> > mbts_l2;

     ElementLink<xAOD::MBTSModuleContainer_v1> mbts_l3;
     std::vector<ElementLink<xAOD::MBTSModuleContainer_v1> > mbts_l4;
     std::vector<std::vector<ElementLink<xAOD::MBTSModuleContainer_v1> > > mbts_l5;
    
     xAOD::ForwardEventInfoContainer_v1 fei_c1;

     DataLink<xAOD::ForwardEventInfoContainer_v1> fei_l1;
     std::vector<DataLink<xAOD::ForwardEventInfoContainer_v1> > fei_l2;

     ElementLink<xAOD::ForwardEventInfoContainer_v1> fei_l3;
     std::vector<ElementLink<xAOD::ForwardEventInfoContainer_v1> > fei_l4;
     std::vector<std::vector<ElementLink<xAOD::ForwardEventInfoContainer_v1> > > fei_l5;
  };

}

#endif // XAODFORWARD_XAODFORWARDDICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"DataLink<DataVector<xAOD::ALFAData_v1> >", payloadCode, "@",
"DataLink<DataVector<xAOD::ForwardEventInfo_v1> >", payloadCode, "@",
"DataLink<DataVector<xAOD::MBTSModule_v1> >", payloadCode, "@",
"DataLink<DataVector<xAOD::ZdcModule_v1> >", payloadCode, "@",
"DataLink<xAOD::ALFADataContainer_v1>", payloadCode, "@",
"DataLink<xAOD::ForwardEventInfoContainer_v1>", payloadCode, "@",
"DataLink<xAOD::MBTSModuleContainer_v1>", payloadCode, "@",
"DataLink<xAOD::ZdcModuleContainer_v1>", payloadCode, "@",
"DataVector<xAOD::ALFAData_v1>", payloadCode, "@",
"DataVector<xAOD::ForwardEventInfo_v1>", payloadCode, "@",
"DataVector<xAOD::MBTSModule_v1>", payloadCode, "@",
"DataVector<xAOD::ZdcModule_v1>", payloadCode, "@",
"ElementLink<DataVector<xAOD::ALFAData_v1> >", payloadCode, "@",
"ElementLink<DataVector<xAOD::ForwardEventInfo_v1> >", payloadCode, "@",
"ElementLink<DataVector<xAOD::MBTSModule_v1> >", payloadCode, "@",
"ElementLink<DataVector<xAOD::TriggerTower_v2> >", payloadCode, "@",
"ElementLink<DataVector<xAOD::ZdcModule_v1> >", payloadCode, "@",
"ElementLink<xAOD::ALFADataContainer_v1>", payloadCode, "@",
"ElementLink<xAOD::ForwardEventInfoContainer_v1>", payloadCode, "@",
"ElementLink<xAOD::MBTSModuleContainer_v1>", payloadCode, "@",
"ElementLink<xAOD::TriggerTowerContainer_v2>", payloadCode, "@",
"ElementLink<xAOD::ZdcModuleContainer_v1>", payloadCode, "@",
"vector<DataLink<DataVector<xAOD::ALFAData_v1> > >", payloadCode, "@",
"vector<DataLink<DataVector<xAOD::ForwardEventInfo_v1> > >", payloadCode, "@",
"vector<DataLink<DataVector<xAOD::MBTSModule_v1> > >", payloadCode, "@",
"vector<DataLink<DataVector<xAOD::ZdcModule_v1> > >", payloadCode, "@",
"vector<DataLink<xAOD::ALFADataContainer_v1> >", payloadCode, "@",
"vector<DataLink<xAOD::ForwardEventInfoContainer_v1> >", payloadCode, "@",
"vector<DataLink<xAOD::MBTSModuleContainer_v1> >", payloadCode, "@",
"vector<DataLink<xAOD::ZdcModuleContainer_v1> >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::ALFAData_v1> > >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::TriggerTower_v2> > >", payloadCode, "@",
"vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > >", payloadCode, "@",
"vector<ElementLink<xAOD::ALFADataContainer_v1> >", payloadCode, "@",
"vector<ElementLink<xAOD::ForwardEventInfoContainer_v1> >", payloadCode, "@",
"vector<ElementLink<xAOD::MBTSModuleContainer_v1> >", payloadCode, "@",
"vector<ElementLink<xAOD::TriggerTowerContainer_v2> >", payloadCode, "@",
"vector<ElementLink<xAOD::ZdcModuleContainer_v1> >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::ALFADataContainer_v1> > >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::ForwardEventInfoContainer_v1> > >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::MBTSModuleContainer_v1> > >", payloadCode, "@",
"vector<std::vector<ElementLink<xAOD::ZdcModuleContainer_v1> > >", payloadCode, "@",
"vector<std::vector<short> >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::ALFAData_v1> > > >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::ForwardEventInfo_v1> > > >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::MBTSModule_v1> > > >", payloadCode, "@",
"vector<vector<ElementLink<DataVector<xAOD::ZdcModule_v1> > > >", payloadCode, "@",
"vector<vector<short> >", payloadCode, "@",
"xAOD::ALFADataAuxContainer_v1", payloadCode, "@",
"xAOD::ALFADataContainer_v1", payloadCode, "@",
"xAOD::ALFAData_v1", payloadCode, "@",
"xAOD::ForwardEventInfoAuxContainer_v1", payloadCode, "@",
"xAOD::ForwardEventInfoContainer_v1", payloadCode, "@",
"xAOD::ForwardEventInfo_v1", payloadCode, "@",
"xAOD::MBTSModuleAuxContainer_v1", payloadCode, "@",
"xAOD::MBTSModuleContainer_v1", payloadCode, "@",
"xAOD::MBTSModule_v1", payloadCode, "@",
"xAOD::ZdcModuleAuxContainer_v1", payloadCode, "@",
"xAOD::ZdcModuleContainer_v1", payloadCode, "@",
"xAOD::ZdcModule_v1", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("xAODForward_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_xAODForward_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_xAODForward_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_xAODForward_Reflex() {
  TriggerDictionaryInitialization_xAODForward_Reflex_Impl();
}
