/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once
#include "plbase/PluginBase_VC.h"
#include "CClumpModelInfo.h"
#include "RenderWare.h"
#include "CVector.h"
#include "RwObjectNameIdAssocation.h"
#include "CRGBA.h"
#include "CPool.h"

class CVehicleModelInfo : public CClumpModelInfo {
public:
    unsigned char m_anLastCarColorId[2];
    char m_szGameName[10];
    unsigned int m_nVehicleType;
    float m_fWheelSize;
    short m_nWheelModelId;
    short m_nHandlingId;
    unsigned char m_nNumDoors;
    unsigned char m_nVehicleClass;
    unsigned char m_nLvl;
    unsigned char m_nNumExtras;
    unsigned short m_nFrq;
private:
    char _pad4E[2];
public:
    CVector m_avecDummyPos[5];
    unsigned int m_nCompRules;
    float m_fBikeSteerAngle;
    RpMaterial *m_apMaterialsPrimary[24];
    RpMaterial *m_apMaterialsSecondary[20];
    unsigned char m_anPrimaryColorId[8];
    unsigned char m_anSecondaryColorId[8];
    unsigned char m_nNumColorVariations;
    unsigned char m_nLastColorVariation;
    unsigned char m_anCurrentColorId[2];
    RpAtomic *m_apExtras[6];
    char *m_pszAnimName;

    //funcs

    void AvoidSameVehicleColour(unsigned char* prim, unsigned char* sec);
    // get vehicle extra with rules. Returns extra id.
    int ChooseComponent();
    // get vehicle second extra with rules. Returns extra id.
    int ChooseSecondComponent();
    void ChooseVehicleColour(unsigned char& prim, unsigned char& sec);
    static RwObject* ClearAtomicFlagCB(RwObject* object, void* data);
    // move all objects from data (it is actually RwFrame *) to frame
    static RwFrame* CollapseFramesCB(RwFrame* frame, void* data);
    // do nothing
    static void DeleteVehicleColourTextures();
    int FindEditableMaterialList();
    static RpAtomic* GetEditableMaterialListCB(RpAtomic* atomic, void* data);
    static RpMaterial* GetEditableMaterialListCB(RpMaterial* material, void* data);
    // gets mat effect of this material. Data is actually int *
    static RpMaterial* GetMatFXEffectMaterialCB(RpMaterial* material, void* data);
    // gets max number of passengers for model
    static int GetMaximumNumberOfPassengersFromNumberOfDoors(int modelId);
    // get wheel position. Wheel is wheel id [0-3]. Local - get local offset (if false it will get 
    // world position)
    void GetWheelPosn(int wheel, CVector& outVec);
    static RpMaterial* HasAlphaMaterialCB(RpMaterial* material, void* data);
    static RpAtomic* HideAllComponentsAtomicCB(RpAtomic* atomic, void* data);
    // loads 'white' texture
    static void LoadEnvironmentMaps();
    static void LoadVehicleColours();
    // set new parent frame for object. Data is actually RwFrame *
    static RpAtomic* MoveObjectsCB(RwObject* object, void* data);
    // setup vehicle model components
    void PreprocessHierarchy();
    // setup objects flag. Data is actually flag (unsigned short)
    static RwObject* SetAtomicFlagCB(RwObject* object, void* data);
    // setup atomic renderer. Data is unused
    static RpAtomic* SetAtomicRendererCB(RpAtomic* atomic, void* data);
    static RpAtomic* SetAtomicRendererCB_BigVehicle(RpAtomic* atomic, void* data);
    // setup boat renderer. Data is unused
    static RpAtomic* SetAtomicRendererCB_Boat(RpAtomic* atomic, void* data);
    // setup heli renderer. Data is unused
    static RpAtomic* SetAtomicRendererCB_Heli(RpAtomic* atomic, void* data);
    static RpAtomic* SetAtomicRendererCB_RealHeli(RpAtomic* atomic, void* data);
    static RpMaterial* SetDefaultEnvironmentMapCB(RpMaterial* material, void* data);
    static RpAtomic* SetEnvironmentMapCB(RpAtomic* atomic, void* data);
    // set current vehicle colour for model
    void SetVehicleColour(unsigned char prim, unsigned char sec);
    void SetVehicleComponentFlags(RwFrame* component, unsigned int flags);
    // unloads 'white' texture
    static void ShutdownEnvironmentMaps();
};

VALIDATE_SIZE(CVehicleModelInfo, 0x174);