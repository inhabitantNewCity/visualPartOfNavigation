#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#ifndef gdbms01_h
#define gdbms01_h

#define BASEEXPORTFUNC _stdcall
typedef int TREE;
typedef short int BASE_INT;
typedef int BASE_INT64;

//== ������ ������� ���������� GDBMS01.DLL
//   ���������� �������� * ����� ������������ � Visual C
typedef struct
{
 unsigned BaseOpen : 1;                                 // 001*
 unsigned BaseReadObject : 1;                           // 002*
 unsigned BaseOpen32 : 1;                               // 003
 unsigned BaseObjectConvertCoord : 1;                   // 004*
 unsigned BDelObjectInfo : 1;                           // 005
 unsigned BaseDeleteServiceObjects : 1;                 // 006*
 unsigned BaseObjectTextToIF : 1;                       // 007
 unsigned BaseObjectTextToIFOpen : 1;                   // 008
 unsigned BaseObjectTextToIFClose : 1;                  // 009
 unsigned BaseObjectTextToIFCont : 1;                   // 010
 unsigned BaseSetForTextToIF : 1;                       // 011
 unsigned BaseInitQuery : 1;                            // 012*
 unsigned BaseInitObject : 1;                           // 013*
 unsigned BaseClose : 1;                                // 014*
 unsigned BaseCloseObject : 1;                          // 015*
 unsigned BaseOpenTextError : 1;                        // 016*
 unsigned BaseSetFormat : 1;                            // 017*
 unsigned BaseGetFormat : 1;                            // 018*
 unsigned BaseSetMetDescriptor : 1;                     // 019*
 unsigned BasePackMode : 1;                             // 020*
 unsigned BaseReadObjectDown : 1;                       // 021
 unsigned BaseSizeObject : 1;                           // 022
 unsigned BaseTreeNavObject : 1;                        // 023
 unsigned BaseTreeNavCode : 1;                          // 024
 unsigned BaseReadNumbers : 1;                          // 025*
 unsigned BaseSetupQuery : 1;                           // 026*
 unsigned BaseReadConnectObjects : 1;                   // 027*
 unsigned BaseReadNameClass : 1;                        // 028*
 unsigned BaseReadName : 1;                             // 029*
 unsigned BaseReadModel : 1;                            // 030
 unsigned BaseReadListkv : 1;                           // 031*
 unsigned BaseReadListkv1 : 1;                          // 032
 unsigned BaseReadPassword : 1;                         // 033*
 unsigned BaseObjectStat : 1;                           // 034
 unsigned BaseReadObjectList : 1;                       // 035*
 unsigned BaseReadCodeList : 1;                         // 036
 unsigned BaseReadObjectKV : 1;                         // 037*
 unsigned BaseReadObjectLKV : 1;                        // 038*
 unsigned BaseGetSemMinMaxValue : 1;                    // 039
 unsigned BaseReadObjectListSem : 1;                    // 040
 unsigned BaseReadClassInfo : 1;                        // 041*
 unsigned BaseGetVersion : 1;                           // 042
 unsigned BaseCheckLists : 1;                           // 043
 unsigned BaseGetFreeNum : 1;                           // 044*
 unsigned BaseObjectCount : 1;                          // 045*
 unsigned BaseInitMultiQuery : 1;                       // 046*
 unsigned BaseMultiReadObjectOpen : 1;                  // 047*
 unsigned BaseMultiReadObjectCont : 1;                  // 048*
 unsigned BaseMultiReadObjectRetry : 1;                 // 049*
 unsigned BaseMultiReadObjectRestore : 1;               // 050*
 unsigned BaseMultiReadObjectListOpen : 1;              // 051*
 unsigned BaseMultiReadObjectListCont : 1;              // 052*
 unsigned BaseMultiReadObjectListRetry : 1;             // 053*
 unsigned BaseMultiReadObjectClose : 1;                 // 054*
 unsigned BaseCheckObject : 1;                          // 055
 unsigned BaseWriteObject : 1;                          // 056*
 unsigned BaseDeleteObject : 1;                         // 057*
 unsigned BaseWriteNameClass : 1;                       // 058*
 unsigned BaseWriteName : 1;                            // 059*
 unsigned BaseSetFindPrecision : 1;                     // 060
 unsigned BaseGetFindPrecision : 1;                     // 061
 unsigned BaseGetErrorMessage : 1;                      // 062
 unsigned BaseWriteModel : 1;                           // 063
 unsigned BaseWriteListkv : 1;                          // 064*
 unsigned BaseWriteListkv1 : 1;                         // 065
 unsigned BaseCheckPoint : 1;                           // 066*
 unsigned BaseCreateListMKO : 1;                        // 067
 unsigned BaseCreateListSem : 1;                        // 068
 unsigned BaseDeleteList : 1;                           // 069
 unsigned BaseDeleteListItem : 1;                       // 070
 unsigned BaseDeleteListCodeNum : 1;                    // 071
 unsigned BaseWriteListItem : 1;                        // 072
 unsigned BaseWriteListItemOpt : 1;                     // 073
 unsigned BaseDeleteLKV : 1;                            // 074
 unsigned BaseMultiMediaItemAdd : 1;                    // 075
 unsigned BaseMultiMediaItemDel : 1;                    // 076
 unsigned BaseMultiMediaItemNo : 1;                     // 077
 unsigned BaseGetMultiMediaItem : 1;                    // 078
 unsigned BaseMultiMediaItemDsc : 1;                    // 079
 unsigned BaseReadSvPr : 1;                             // 080*
 unsigned BaseGetAdrSvPrForNumber : 1;                  // 081*
 unsigned BaseDeleteObjectSvPr : 1;                     // 082
 unsigned BaseDeleteSvPr : 1;                           // 083*
 unsigned BaseAddSvPr : 1;                              // 084*
 unsigned BaseAddPrToPoint : 1;                         // 085*
 unsigned BaseDeletePrNumber : 1;                       // 086*
 unsigned BaseGetAdrSemSP : 1;                          // 087*
 unsigned BaseCoordConvert : 1;                         // 088
 unsigned BaseCodeStr : 1;                              // 089*
 unsigned BaseTransMKO : 1;                             // 090*
 unsigned BaseNumbersCharToInt : 1;                     // 091*
 unsigned BaseNumbersCharToLong : 1;                    // 092
 unsigned BaseNumbersCharToLongZ : 1;                   // 093
 unsigned BaseDateEncode : 1;                           // 094*
 unsigned BaseDateDecode : 1;                           // 095*
 unsigned BaseObjectSquare : 1;                         // 096
 unsigned BaseObjectSquare4 : 1;                        // 097
 unsigned BaseObjectSquareAll : 1;                      // 098*
 unsigned BasePrintObjectFile : 1;                      // 099
 unsigned BasePrintObjectToFile : 1;                    // 100
 unsigned BasePointInout : 1;                           // 101
 unsigned BaseCopyObject : 1;                           // 102*
 unsigned BaseCompCode : 1;                             // 103*
 unsigned BaseGetError : 1;                             // 104
 unsigned BaseConvFloatLong : 1;                        // 105
 unsigned BaseCoordIntToLong : 1;                       // 106
 unsigned BaseSelectObject : 1;                         // 107
 unsigned BaseMultiSelectObject : 1;                    // 108
 unsigned BaseMultiSelectCodeNumber : 1;                // 109
 unsigned BaseMultiSelectOneSP : 1;                     // 110
 unsigned BaseFormKV : 1;                               // 111
 unsigned BaseGetMemory : 1;                            // 112
 unsigned BaseFreeMemory : 1;                           // 113
 unsigned BaseReadSem : 1;                              // 114
 unsigned BaseReadSemFromNumber : 1;                    // 115
 unsigned BaseAddOneSem : 1;                            // 116
 unsigned BaseWriteOneSem : 1;                          // 117
 unsigned BaseDeleteOneSem : 1;                         // 118
 unsigned BaseFormSem : 1;                              // 119
 unsigned BaseReadSemComp : 1;                          // 120
 unsigned BaseSemCount : 1;                             // 121*
 unsigned BaseFeatureSplit : 1;                         // 122
 unsigned BaseSemLength : 1;                            // 123
 unsigned BaseSemValueUpdate : 1;                       // 124
 unsigned BaseReadSTRX11 : 1;                           // 125
 unsigned BaseGetX11SingleFieldCode : 1;                // 126
 unsigned BaseGetX11SingleFieldNumb : 1;                // 127
 unsigned BasePrintSemValue : 1;                        // 128
 unsigned BasePrintSemValue5 : 1;                       // 129
 unsigned BaseReadSemValue : 1;                         // 130
 unsigned BaseReadFeature : 1;                          // 131*
 unsigned BaseReadFeatureComp : 1;                      // 132*
 unsigned BaseDeleteFeature : 1;                        // 133*
 unsigned BaseDeleteFeatureComp : 1;                    // 134*
 unsigned BaseAddFeature : 1;                           // 135*
 unsigned BaseAddFeatureComp : 1;                       // 136*
 unsigned BaseUpdateFeature : 1;                        // 137*
 unsigned BaseUpdateFeatureComp : 1;                    // 138*
 unsigned BaseWriteImageFile : 1;                       // 139
 unsigned BaseWriteImageMemory : 1;                     // 140
 unsigned BaseDeleteImage : 1;                          // 141
 unsigned BaseObjectDeleteImage : 1;                    // 142
 unsigned BaseReadImageFile : 1;                        // 143
 unsigned DDCReadImageFile : 1;                         // 144
 unsigned BaseReadImageMemory : 1;                      // 145
 unsigned BaseObjectReadImageFile : 1;                  // 146
 unsigned BaseObjectReadImageMemory : 1;                // 147
 unsigned BaseSetAdrSem : 1;                            // 148
 unsigned BaseSetAdrSv : 1;                             // 149
 unsigned BaseSetAdrPr : 1;                             // 150
 unsigned BaseSetAdrSquare : 1;                         // 151
 unsigned BaseSetAdrMet : 1;                            // 152
 unsigned BaseSetAdrVideo : 1;                          // 153
 unsigned BaseSetAdrText : 1;                           // 154
 unsigned BaseFindObjectByCoordInt : 1;                 // 155
 unsigned BaseFindObjectByCoordFloat : 1;               // 156
 unsigned BaseFindDOByCoordInt : 1;                     // 157
 unsigned BaseFindAllDOByCoordInt : 1;                  // 158
 unsigned BaseFindAllDOByCoordFloat : 1;                // 159
 unsigned BaseFindDOByCoordFloat : 1;                   // 160
 unsigned BaseFindObjectStreamInt : 1;                  // 161
 unsigned BaseFindObjectStreamFloat : 1;                // 162
 unsigned BaseFindAnyObjectCoord : 1;                   // 163
 unsigned BaseFindAnyObjectCoordIF : 1;                 // 164*
 unsigned BaseMultiFindAnyObjectCoord : 1;              // 165
 unsigned BaseMultiFindAnyObjectCoordIF : 1;            // 166*
 unsigned BaseScaleAnalyze : 1;                         // 167
 unsigned BaseGetLabel : 1;                             // 168
 unsigned BaseSetFindMaxDistance : 1;                   // 169*
 unsigned BaseGetFindMaxDistance : 1;                   // 170*
 unsigned DDCOpen : 1;                                  // 171
 unsigned DDCClose : 1;                                 // 172
 unsigned DDCReadNameClass : 1;                         // 173
 unsigned DDCReadName : 1;                              // 174
 unsigned DDCReadObject : 1;                            // 175
 unsigned DDCInitQuery : 1;                             // 176
 unsigned DDCReadHeader : 1;                            // 177
 unsigned DDCFindObjectByCoordInt : 1;                  // 178
 unsigned DDCFindObjectByCoordFloat : 1;                // 179
 unsigned DDCFindAllDOByCoordInt : 1;                   // 180
 unsigned DDCFindAllDOByCoordFloat : 1;                 // 181
 unsigned BaseReadGlobal : 1;                           // 182
 unsigned BaseReadGlobalByPart : 1;                     // 183
 unsigned BaseReadClassInfoObject : 1;                  // 184*
 unsigned BaseMemoryMove : 1;                           // 185
 unsigned BasePackCode : 1;                             // 186
 unsigned BaseSetFlagCheckPr : 1;                       // 187
 unsigned TreeSK : 1;                                   // 188
 unsigned TreeS : 1;                                    // 189
 unsigned TreeCPY : 1;                                  // 190
 unsigned TreeSKD : 1;                                  // 191
 unsigned TreeSD : 1;                                   // 192
 unsigned a2daPrm : 1;                                  // 193
 unsigned BaseCalcSize : 1;                             // 194
 unsigned BaseCheckClassCode : 1;                       // 195
 unsigned BaseCopy : 1;                                 // 196
 unsigned BaseSetFeatureFilterRead : 1;                 // 197
 unsigned BaseSetFeatureFilterNoRead : 1;               // 198
 unsigned BaseGetFeatureFilterReadCount : 1;            // 199
 unsigned BaseGetFeatureFilterNoReadCount : 1;          // 200
 unsigned BaseGetFeatureFilterRead : 1;                 // 201
 unsigned BaseGetFeatureFilterNoRead : 1;               // 202
 unsigned BaseSetFeatureFilterService : 1;              // 203
 unsigned BaseGetFeatureFilterService : 1;              // 204
 unsigned BaseGetFeatureFilterServiceCount : 1;         // 205
 unsigned BaseSwapSvPr : 1;                             // 206
 unsigned BaseSortPr : 1;                               // 207
 unsigned BaseCreateListWindows : 1;                    // 208
 unsigned BaseSetMaxCodePositions : 1;                  // 209
 unsigned BaseGetMaxCodePositions : 1;                  // 210
 unsigned BaseChangeCodeObject : 1;                     // 211
 unsigned BaseChangeCodeInList : 1;                     // 212
 unsigned BaseAddMetric :1;                             // 213*
 unsigned BaseDelMetric :1;                             // 214*
 unsigned BaseUpdateMetric :1;                          // 215*
 unsigned BaseGetFreeNumbers :1;                        // 216*
 unsigned BaseFeatureDelFull :1;                        // 217
 unsigned BaseExtractDO :1;                             // 218
 unsigned BaseCorrRelations :1;                         // 219
 unsigned BaseCreateListWinForRegion :1;                // 220
 unsigned BaseGetSelectInfo :1;                         // 221
 unsigned BaseObjectLengthAll :1;                       // 222
 unsigned BasePointInoutEps : 1;                        // 223
 unsigned BaseCheckObjectFull : 1;                      // 224
 unsigned TreeOpen : 1;                                 // 225
 unsigned TreeClose : 1;                                // 226
 unsigned BaseReadObjectSV : 1;                         // 227
 unsigned BaseDeleteObjectSV : 1;                       // 228
 unsigned BaseWriteApplicationInfo : 1;                 // 229
 unsigned BaseWriteUserInfo : 1;                        // 230
 unsigned BaseSetCodeSemPoint : 1;                      // 231
 unsigned BaseGetCodeSemPoint : 1;                      // 232
 unsigned BaseGetNumberQuery : 1;                       // 233
 unsigned BaseCopyObjectEasy : 1;                       // 234
 unsigned BaseWriteObjectSV : 1;                        // 235
 unsigned BaseDeleteObjects : 1;                        // 236
 unsigned BaseCalcSizeDouble : 1;                       // 237
 unsigned BaseNumbersCharToDouble : 1;                  // 238
 unsigned BaseAddFeatureCompUniversal : 1;              // 239
 unsigned BaseCreateListWindowsByCoords : 1;            // 240
 unsigned BaseSetCoeffCoordGeo : 1;                     // 241
} GBASE_FUN01;


//--------------- ��� ������ � ���������� ����������� -----------------
#define MULTI_BASE          1  // ������� ����������� �������� � ������� ����
#define MULTI_FILE          0  // ������� ����������� �������� � �����
#define MULTI_NO            0  // �� ������������ ������� �����������
#define MULTI_DEL           1  // ������� �������
#define MULTI_ADD           2  // �������� �������
#define MULTI_DSC           3  // �������� �������� ��������

//--------------- ���� ������ ----------------------------------------
#define BERR_OK             0  // ���������� ����������
#define BERR_MEM            1  // ��� ����������� ������
#define BERR_NOINF          2  // ��� ���������� �� �������
#define BERR_QUERY          3  // ������ � �������
#define BERR_PARAM          4  // ������ � ����������
#define BERR_PASS           5  // �������� ������
#define BERR_READ           6  // ���� ������� ������ �� ������
#define BERR_FILEBASE       7  // ���� �� �������� ����� ������
#define BERR_BASE           8  // ������ � ���� ������
#define BERR_COORD          9  // �������� ����������
#define BERR_WAIT          10  // ���� ������ ������ ������ �������
#define BERR_NOCLOSE       11  // ���� � ������������� ���������
#define BERR_BLOCK         12  // ���� �������������
#define BERR_FORMAT        13  // �������� ������ ���� ������
#define BERR_YESINF        14  // ���������� ��� ����
#define BERR_NUMBER        15  // ������ � ������ �������
#define BERR_METRIC        16  // ������ ������� �� ��������������
#define BERR_SLMKO         17  // ������ � �������� ������ �������
#define BERR_RLMKO         18  // ������ � ���� �������
#define BERR_CANCEL        19  // �����
#define BERR_FILE          20  // ������ � �����
#define BERR_MAX           21  // ���������� ��������� ��������� ����������� ����������
#define BERR_REFOBJ        22  // � ���� ��� ������� �� ������
#define BERR_OBJECT        23  // ������ � ������� � ������
#define BERR_RO            24  // ������ � ��������� ��������������� �������
#define BERR_DISK          25  // ������������ ����� �� �����

//------- ����������� ���� ������ -------------------------------
#define BASE_ERR_NUMBER    1
#define BASE_ERR_CODE      2
#define BASE_ERR_NAME      3
#define BASE_ERR_EXTFILE   4
#define BASE_ERR_FILE      5
#define BASE_ERR_FORMAT    6

//--------- ������� � ������������ ���� ������
#define  BASE_ERR_READ     1000       // ������ ������ �� ����
#define  BASE_ERR_WRITE    2000       // ������ ������ � ����
#define  BASE_ERR_DELETE   3000       // ������ ��� �������� �� ����
#define  BASE_ERR_NIKA     4000       // ������ ����

//-------  �������� ��������� ��� BaseReadObjectListSem ---------
#define  BAL 0     //  �������
#define  BEQ 1     //  �����
#define  BNE 2     //  �� �����
#define  BLE 3     //  ������ ��� �����
#define  BLT 4     //  ������
#define  BGE 5     //  ������ ��� �����
#define  BGT 6     //  ������
#define  BIN 7     //  � ���������
#define  BOU 8     //  ��� ���������

//----------- ��� �������� �������� �� BDelObjectInfo
#define DSubTree    2    // �������� ������ ��������
#define DCode       3    // �������� �������� ���������� ������� ����

//-------- ������ ���� ������ -------------------------------------
//         ��������� ������ ��� ������ � ����
#define    BASE_FORMAT_2     2       // ������ 2.0 - ������ DOS (��� �����-2)
#define    BASE_FORMAT_3     3       // ������ 3.1 - ������ Windows

//---------- ��� ���������� ������� �������� ���� ������ ---------------
#define    BASE_NOPACK       0     // �� �����������
#define    BASE_PACK         1     // ����������� ���������� ��� ������ � ����

//-------- ��� ���������� � ����� � ������� ������ �� ---------------------
#define    DDC_TYPE_BASE     0       // ����
#define		  DDC_TYPE_STR      1       // ������
#define		  DDC_TYPE_DOC      2       // ������������
#define			 DDC_TYPE_FILE     3       // ����� �����
#define			 DDC_TYPE_NONE     4       // �� ���������

//------- ����� �������� ����� � ������� ������ ----------------------------
#define   DDC_LIST_YES    1          // � ������������� ������ �������� ���
																																					//  �������� �������
#define   DDC_LIST_NO     0          // ��� ������������ ������ ��������

//---------- ������ ��������� ������ ��� ����� ������� ----------------------
#define  BASE_NEW_FORMAT       0    // ������ ��� ������ ���������� ��������
																																				// ��� ������ ������� �� ���� ������
																																				// ����� � ���������� �������������� �
																																				// ����������� ������ � ���� ���������
																																				// ���������������� ������

#define  BASE_OLD_FORMAT       1    // ������� ��� ���� ������� ��������
																																				// �������������
																																				// ����� � ���������� ������������� �
																																				// �������� ������������� �������

#define  BASE_OLD_FORMAT_DYN   2    // ������ ��� ������ � ����������:
#define OBJ_SCALE_01       0x80000000
#define OBJ_SCALE_02       0x40000000
#define OBJ_SCALE_03       0x20000000
#define OBJ_SCALE_04       0x10000000
#define OBJ_SCALE_05       0x08000000
#define OBJ_SCALE_06       0x04000000
#define OBJ_SCALE_07       0x02000000
#define OBJ_SCALE_08       0x01000000
#define OBJ_SCALE_09       0x00800000
#define OBJ_SCALE_10       0x00400000
#define OBJ_SCALE_11       0x00200000
#define OBJ_SCALE_12       0x00100000
#define OBJ_SCALE_13       0x00080000
#define OBJ_SCALE_14       0x00040000
#define OBJ_SCALE_15       0x00020000
#define OBJ_SCALE_16       0x00010000
#define OBJ_SCALE_17       0x00008000
#define OBJ_SCALE_18       0x00004000
#define OBJ_SCALE_19       0x00002000
#define OBJ_SCALE_20       0x00001000
#define OBJ_SCALE_21       0x00000800
#define OBJ_SCALE_22       0x00000400
#define OBJ_SCALE_23       0x00000200
#define OBJ_SCALE_24       0x00000100
#define OBJ_SCALE_25       0x00000080
#define OBJ_SCALE_26       0x00000040
#define OBJ_SCALE_27       0x00000020
#define OBJ_SCALE_28       0x00000010
#define OBJ_SCALE_29       0x00000008
#define OBJ_SCALE_30       0x00000004
#define OBJ_SCALE_31       0x00000002
#define OBJ_SCALE_32       0x00000001
//------------------- ��� ������� ���������� ����� ---------------------
#define BaseScaleOneYes  0   // ������� ���� �� ���� ��������� ������
#define BaseScaleAllYes  1   // �������� ��� ��������� �������
#define BaseScaleOneNo   2   // �������� ���� �� ���� ��������� ������
#define BaseScaleAllNo   3   // ��������� ��� ��������� �������

//------------------ ���� �������� �������������� -----------------------
#define  XAR_TYPE_INT         1     // ����� �������� (2 �����)
#define  XAR_TYPE_DOUBLE      2     // ������������ � ������� ��������� (8 ����)
#define  XAR_TYPE_LONG        3     // ����� ������� (4 �����)
#define  XAR_TYPE_TEXT        4     // ����� (1 - 255 ����)
#define  XAR_TYPE_STRUCT      5     // ����������� ����� (1 - 129 �������)
#define  XAR_TYPE_FLOAT       6     // ������������ �������� (4 �����)
#define  XAR_TYPE_NO          7     // ��� ��������
#define  XAR_TYPE_COORD       8     // �������������� ���������� (8 ����)
#define  XAR_TYPE_DATE        9     // ���� (4 �����)
#define  XAR_TYPE_COMPLEX    10     // ������� ��������������
#define  XAR_TYPE_RECORD     11     // ������

//------------- ����� ��� ������ � ���������������� ------------------------
#define  OPEN_SEM         0    // ������ ������������� �������
#define  READ_SEM         1    // ������ ����� ��������������
#define  NEXT_SEM         2    // ������ ��������� ��������������
																															//  � �������� ������� �� ������
																															//  ������������� �������
#define UPDATE_SEM        3    // ������ ��� ���������� ��������������
#define CHANGE_SEM        4    // ������ ������ ��������������
#define DELETE_SEM        5    // �������� ��������������
#define ADD_SEM_CODE      6    // ���������� �������������� �����
																															// ��������������� � ��������� �����
#define ADD_SEM_NUMBER    7    // ���������� �������������� �����
																															//  ��������������� � ���������
																															//  ���������� �������
#define DELETE_SEM_CP     8    // �������� ��������������, ���������
																															//  ����� � ������� ��������
#define DELETE_SEM_NUMBER 9    // �������� �������������� �� ����������� ������
#define  OPEN_SEM_CODE   10    // ������  ������� �������������,
                               // �������� ������ �����
#define BASE_FEAT_LOC_OBJ   1  // ������ �������������� �� �������
#define BASE_FEAT_LOC_SV    2  // ������ �������������� �� �����
#define BASE_FEAT_LOC_PR    3  // ������ �������������� �� ����������
#define BASE_FEAT_LOC_FIELD 4  // ������ �������������� �� ������������� ����

//-------------- ����� ��� ������ � ������ �������� � ���� ------------------
#define  OPEN_TREE           0     // ������ ������� � ������� ���������
#define  OPEN_CODE_SELECT    1     // ���������� ������ ��� ������
																																			//  �������� ��������� ������� ����
#define  OPEN_CODE           2     // ������ ������� ��������
																																			//  ��������� ������� ����
#define  OPEN_LIST           0     // ������ ������� �� ���������������� ������
#define  READ_NEXT           3     // ������ ���������� ������� � ������
#define  READ_RETRY          4     // ��������� ������ ������ ���
																																			//  ������������ � ������ �������
#define  READ_WR             5     // ���������� ������ ��� ������������
																																			//  � ������ �������
#define  READ_SELECT         6     // ���������� ������ ������� ��
																																			//  ������
#define  READ_RESTORE        7     // �������������� �������
#define  READ_DELETE         8     // �������� ������ ������ ���
																																			//  ������������ � ������ �������
#define  READ_SIZE           9     // ����������� �������� ������
																																			//  ��� ������������ � ������
																																			//  �������
#define  READ_RIGHT         10     // ������ ������ �� ������
#define  READ_LEFT          11     // ������ ����� �� ������
#define  READ_UP            12     // ������ ����� �� ������
#define  READ_DOWN          13     // ������ ���� �� ������
#define  READ_FIRST         14     // ������ ������� �� ������
#define  READ_LAST          15     // ������ ���������� �� ������
#define  READ_CLOSE         16     // �������������� �������� �������
#define  BASE_FIND_OPEN      0     // �������� ������� �� ������������ ����� �������
#define  BASE_FIND_NEXT      1     // ����� ���������� �������

#define  BASE_FIND_CLOSE     2     // �������� �������

//----------- �������������� ��������� ����� ---------------------------------
#define  FIND_BY_METRICS     1     // ����� �� �������
#define  FIND_BY_SEM         2     // ����� �� ����������� ����� �������� ������������� �������
#define  FIND_BY_SV          4     // ����� �� ����������� ����� �������� ������������� ������
#define  FIND_BY_PR          8     // ����� �� ����������� ����� �������� ������������� ����������
#define  FIND_BY_ALL        15     // ������ �����
#define  FIND_DO            16     // ����� �� ����������� ����� ��������
                                   //  ����������� �������
#define  FIND_PRECISION_SMALL  0   // ��� ������ �� ������ �������
#define  FIND_PRECISION_LARGE  1   // ��� ������ �� �������� �������

//--------------- ����� ������� ������ ������� ------------------------------
#define  OBJ_CODE            0     // ������ ����������������� ����� �������:
																																			//  ���, �����, ����, �����
#define  OBJ_SEM             1     // ���������
#define  OBJ_SV              2     // �����
#define  OBJ_PR              4     // ����������
#define  OBJ_SQUARE          8     // ��������
#define  OBJ_METRIC         16     // �������
#define  OBJ_ALL            31     // ���� ������ ��� ������ � ���� �����������)
#define  OBJ_TEXT           32     // �����
#define  OBJ_VIDEO          64     // ���� �����������
#define  OBJ_FULL          127     // ������ ����� �������
#define  OBJ_SEM_HEX       128     // ������ �-�� � ��������.�������
#define  OBJ_VIDEO_ALL       2     // �������������� ���� � ���������� �������
																																			//  ��� ������ ����� ���� �����������
#define  OBJ_SEM_PARTS     256     // �������������� ����� ������ ���� �������������
                                   // ��������������� ������� �� ��� ������
#define  OBJ_SV_PARTS      512     // �������������� ����� ������ ���� ������
                                   // ��������������� ������� �� ��� ������
#define  OBJ_PR_PARTS     1024     // �������������� ����� ������ ���� ����������
                                   // ��������������� ������� �� ��� ������
#define  OBJ_VIDEO_PARTS  2048     // �������������� ����� ������ ����� �����������
#define  OBJ_PR_SORT      4096     // �������������� ����� ���������� ����������
                                   //  ��� ������ ��������������� �������
#define  OBJ_NUMBER       8192
#define  OBJ_SCALE       16384
#define  OBJ_CODE_SVPR   32768
#define  OBJ_VIDEO_EXT   65536
#define  OBJ_VIDEO_NAME 131072

//------------------ ����� ������ ������� -----------------------------------
#define  WRITE_DELETE        0     // ������ ������� � ��������� �������
#define  WRITE_ADD           1     // ������ ������� ����������
																																			//  ���������
#define  WRITE_NO            2     // �� ���������� ������ ���� ��
																																			//  ��� ����
#define  WRITE_AUTO          3     // ������ ������� � ��������������
																																			// ����������
//---------- �������������� ����� ������ ��� ������ ������� � ������ WRITE_ADD
#define  WRITE_SV_DELETE     0     // �������� ������ ������ �
																																			//  ������ �����
#define  WRITE_SV_ADD        4     // ���������� ����� ������
																																			//  ���������� ���������
#define  WRITE_SV_NO         8     // �� ���������� ����� ���� ��� ��� ����
#define  WRITE_SV_AUTO      12     // ���������� ����� ������ � ������
#define  WRITE_PR_DELETE     0     // ���������� ������ ��� ����������
#define  WRITE_PR_ADD       16     //
#define  WRITE_PR_NO        32     //
#define  WRITE_PR_AUTO      48     //

//------------------ ����� ��� ����� ������ � ���������� -----------------
#define  BASE_SV             0   // �����
#define  BASE_PR             1   // ����������
#define  BASE_SVPR_NORENUM   2   // �� ���������������� ����� ������/����������
#define  BASE_SVPR_RENUM     0   // ���������������� ����� ������/����������
#define  BASE_SVPR_FIRST    -1   // ������� ����� � ������ ������
#define  BASE_SVPR_LAST     -2   // ������� ����� � ����� ������
#define  BASE_SVPR_ADR      -3   // ������� �� ������
#define  BASE_SVPR_POINT    -4   // ������� �� ������ ����� � �������
#define  BASE_SVPR_OPEN      0   // ������� ������ �� ������ ������/����������
#define  BASE_SVPR_READ      1   // ��������� ��������� �����
#define  BASE_SVPR_READOR    2   // ��� ������ - ������� "���"
#define  BASE_SVPR_READAND   0   // ��� ������ - ������� "�"
#define  SVPR_OPEN           0
#define  SVPR_READ           2

//-------------- ����� ��� ������ �� ������� ���� --------------------------
#define  LISTKV_ALL          0   // ������ ����� �������� ������ ����
#define  LISTKV_HEADER       1   // ������ ������ ���������
																																	//  ���������� � ������ ����
#define  LISTKV_UPDATE       2   // ������ ������������� ��������
																																	//  ������ ����
#define  LISTKV_NOUPDATE     3   // ������ ������ �������������
																																	//  �������� ������ ����
#define  BASE_BEGIN_LISTKV   30000   // ������ ������ ���� � ���������������
																																					// �������. ���� 1 ����� ����� ������
																																					// 30001

//----------------- ����� ��� ������ � ��������� �������� -----------
#define  SYSJN_ON            0   // ����������� ������� � ����
#define  SYSJN_OFF           1   // ���������� �������
#define  SYSJN_INFO          2   // ��������� ���������� �� �������
																																	//  ������� � ����

//---------------- ����� ��� ������ � ��������������� -----------------------
#define  CLASS_OBJECT        1   // ������ ���������� �� �������
#define  CLASS_FEATURE							2   // ������ ���������� � ��������������

//----------------- ��� ���������� ������������ �������� ------------------
#define  BASE_MET_COUNT_2    0   // ����������� 2
#define  BASE_MET_COUNT_3    8   // ����������� 3
#define  BASE_MET_INTEGER    0   // �����
#define  BASE_MET_FLOAT      1   // ������������
#define  BASE_MET_LOGICAL    2   // ����������

//==================== ������������� �������������� ===============
typedef struct
{
	BASE_INT Code[10];    // ��� �������������� (������, ���������� ��� ��� 0)
	unsigned long Number; // ���������� ����� �������������� �������
                       // ������� ��� ����������� ���� (0 ���������� 1).
} FEATURE_CODE;
//==================== �������� �������������� ===================
typedef union
{
	BASE_INT I;               // ��� 1      ����� ��������
	double D;                 // ��� 2      ������������ ������� ��������
	long L;                   // ��� 3      ����� �������
	char T[260];              // ��� 4      �����. ������ � ���� ������ ������
																											//            ������������ � ��������� MS DOS
																											//            ��� ������ ������������ ��� �������������
																											//            �������������� � ��������� ANSI Windows
	BASE_INT S[130];          // ��� 5      ����������� �����
	float  F;                 // ��� 6      ������������ ��������
	struct                    // ��� 8      �������������� ����������:
	{
		BASE_INT gm[2];          //            ������� � ������
		float c;                 //            �������
	} gmc;
	unsigned long DATE;       // ��� 9      ���� (���������� ����� ��� ��
																											//                    01.01.1900)
	BASE_INT *pComplex;       // ��� 10     ������� ��������������. ��������� ��
                           //            �������� ������� �-��
	BASE_INT *pRecord;        // ��� 11     ������. ��������� �� ������.
                           //            1-� ����� - ������ ������ � ������
                           //            ��� ����� ����� �����
} BASE_XAR_VALUE;
//================ ������� ��������� ���� ����������� ======================
typedef struct
{
	unsigned long Number;   // ����� �������� ����������� (> 0)
 char Description[256];  // �������� ��������
 char Type[8];           // ��� �������� (���������� �����, ��������, BMP)
 int Location;           // �������������� ��������:
                         //  MULTI_BASE - � ������� ���� ������
                         //  MULTI_FILE - � ��������� �����
 char FileName[256];     // ��� ����� (� �����������) � ��������� ��� Location=MULTI_FILE
 int Action;             // ���� ��������� �������� ��� ������ ������� � ����:
                         //  MULTI_NO - �� ���������� � ����
                         //  MULTI_DEL - ������� � ����
                         //  MULTI_ADD - �������� � ���� ����������� ������� � ����
 unsigned long Size;     // ������ �������� � ������
	unsigned long Adr;      // ����� ������ �������� � ���� �����������
																									//  ��� ������ ����� ���� �������
} VIDEO_HEADER;
//========= ��������� ��������� ������ ���� (���������) ���� ������ ====
typedef struct
{
	double Xmin;    // ���������� ������ ������� � ������� ��������
	double Ymin;    //  ���� ������������� �����, ������������ ����
	double Xmax;    //  (� �������� ���� ������)
	double Ymax;
	long Kx;        // ���������� ���� �� �����������
	long Ky;        // ���������� ���� �� ���������
	double Dx;      // ������ ���� �� ����������� (� �������� ����)
	double Dy;      // ������ ���� �� ��������� (� �������� ����)
	long Count;     // ���������� ����
} BASE_LISTKV;
//========= ��� ������ ���������� � ��������� �� ������� ������� =====
typedef struct
{
 char FileName[256];    // ������ ��� ����� ���� ������
 BASE_INT Code[10];     // ��� �������
 unsigned long Number;  // ����� �������
 BASE_INT64 Scale;      // ���������� ����� �������
 double X;              // ���������� ��������� ����� � ��������� �������
 double Y;
 int Type;              // ��� ����������, �� ������� ������ ������:
                        //  FIND_BY_METRICS - �� ������� �������
                        //  FIND_BY_SEM - �� ��������������� ������
                        //  FIND_BY_SV - �� ��������������� �����
                        //  FIND_BY_PR - �� ��������������� ����������
 int NumberPoint;       // ���������� ����� ��������� ����� � ������� ������� ���
                        //  �������������� ���������� �������
 int NumberSv;          // ���������� ����� �����, �� ��������������
                        //  ������� ������ ������
 int NumberPr;          // ���������� ����� ����������, �� ��������������
                        //  �������� ������ ������
 BASE_INT64  ScaleSvPr; // ���������� ����� ���������� ��� �����
 BASE_INT CodeSvPr[10]; // ��� ������������/���������� �������, ���� ������� ������
                        //  ������ �� �������������� ����������/�����
 BASE_INT CodeSem[10];  // ��� ��������������, �� ������ ������� ������ ������
 int NumberSem[102];    // ���������� ������ ��������������, �� �������
                        //  ������ ������ (�� ������� ����������� � �������
                        //  ��������������). NumberSem[0] - ���������� �������
 float FindTime;        // ����� ������ � ��������
 double Distance;       // ���������� �� ��������� ����� � ��
} GBASE_FIND_ANY_OBJECT;
//=== ������� ������ ��������, ������� �� ��������� � ������ �� ������� ======
typedef struct
{
 BASE_INT Code[10];     // ��� �������
 unsigned long Number;  // ����� ������� (���� 0, �� Code ���������
                        //  �� ����������� ��������)
 int TypeFind;          // ��� ����������, �� ������� ������ �� ���������
                        //  � ������ (������������):
                        //  FIND_BY_METRICS
                        //  FIND_BY_SEM
                        //  FIND_BY_SV
                        //  FIND_BY_PR
                        //  FIND_BY_ALL ��� 0 - ������ ������ �� ��������� � ������
} GBASE_NOT_FIND_OBJECT;
//================= ��������� ����������� �������  =====================
//    ���������� (���������) ������� ����������� ��� ������ ������� ��
//    ���� ������. ����� ������� ������� ��� ��������� ������ ����
//    ��������������� �������� BaseInitObject.
//    ����� ������� ������� � ���� ������������ ������ ������������ �
//    ��������� ������� ��� ����������� ��� ������ ����.
//    �� ��������� ������ � �������� �� (� �������������� � ��� ���������)
//    ������ ���� ������ �������� BaseCloseObject
//
typedef  struct
{
	unsigned long   Number;        // ����� ������� (�������� ��� ������,
																																//  �������� ��� ������)
	unsigned long   NumberNew;     // ����������� �������� ����� ������ �������
																																//  � ����: ����� �������, ��� �������
																																//  �� ������� � ����
	int       Scale;        // ���������� ����� ������� (�������� ��� ������,
																																//  �������� ��� ������)
	unsigned int  FlagScale;       // ���� ������ ����� �������. ������ ����
																																// ����������� ����� ������� ������� � ����:
																																//     1 - ���������� ����� �������
																																//     0 - �� ���������� �����
	long           Key;            // ������� (����) ������� � ������� (��������
																																//  ��� ������, �������� ��� ������)
	unsigned int   FlagKey;        // ���� ������ ����� �������. ������ ����
																																// ����������� ����� ������� ������� � ����:
																																//     1 - ���������� ���� �������
																																//     0 - �� ���������� ����

//---------- ��������� �� ����� ������� ��� NULL ��� ����������
//  ����������� �������� ��� ������������ ������� ��������� ������
//  ��� ����������� �������������, � ��� ������ ����� �� ��� �������� ������
//  ��� ��������������� ����� �������
	BASE_INT       *pSem;          // ��������� ( ������ �� 65536 ����)
	void           *pSv;           // �����. ������� ��� ����� �������������
																																// ����� ����:
																																//  ����� 1 (����� ������). ����� ������������
																																// � ���� ���������������� �������������
																																// ������. ������ ����� �����
																																// ��������� ���� BASE_SVPR.
																																// ����� ����� ���� �� 2**31 ������
																																//  ����� 2 (������ ������). ����� ����� �
																																// ����� �������� �������. ������
																																// ����� ����� ��������� BASE_SVPR_OLD
																																// ������ �������� �������������
																																//  ����� 3 (������-������������ ������).
																																// ����� ����� � ����� �������� �������.
																																// ������ ����� ����� ��������� BASE_SVPR_OLD
																																// ������ ��� ������ ������� �����������
	void           *pPr;           // ����������. ������� ��� ����� �������������:
																																//  ����� 1 (����� ������). ����������
																																// ������������ � ���� ���������������
																																// ������������� ������.
																																// ������ ���������� �����
																																// ��������� ���� BASE_SVPR.
																																// ����� ����� ���� �� 2**31 ����������
																																//  ����� 2 (������ ������). ����������
																																// ����� � ����� �������� �������.
																																// ������ ���������� ����� ���������
																																// BASE_SVPR_OLD
																																// ������ �������� �������������
																																//  ����� 3 (������-������������ ������).
																																// ���������� ����� � ����� �������� �������.
																																// ������ ���������� ����� ��������� BASE_SVPR_OLD
																																// ������ ��� ������ ������� �����������
	void       *pSquare;           // ��������. ���������� ��������� (4-� ��������
																																//  ���������) �������� � ��������� ����
																																//  qSquare. ������ ���� ���������
																																//  �� ���������. ���� ��������� �����
																																//  ������������ ���������
	void       *pMet;              // �������. ���������� ����� � �������
																																//  �������� � ��������� ���� qMet.
																																//  ������ ���� ������� �� ���������.
																																//  �������� �������� ���������� � ����
																																//  ������� ������ �����������
																																//  CountItemsMet, SizeItemMet � TypeItemMet
																																//  � ����� ���������� �������� ����� ������
	char       *pText;             // �����. ��������� �������� ������� (������
																																//  � ������ � ���� qText � sText -
																																//  �� 65536 ����)
	VIDEO_HEADER *pVideo;          // �����������. ���� ����������� �������
																																//  ����� ���� ������������ � ���� ������:
																																// ����� 1. ���������� ���� �����������
																																//  ������� � ��������� VIDEO_HEADER
																																// ����� 2. ���������� ���� �����������
																																//  �������, � �� ��� ��� �������� ����
																																//  ����������� � ������� �� �������������
																																//  � �����������
//************* ������� ������ � ���� ���� ����������� �������� BaseWriteObject.
//*** ��� ����� 2: ��� �������� ���� ����������� ������������ � ���� (��� ���������
//                 �������� ��� � ������������ ������� � ������ WRITE_ADD)
//*** ��� ����� 1: � ���� ������ ����������� ������ �������� �����������,
//                 ���������� � ����������� Action=MULTI_ADD. ���� Location=MULTI_FILE,
//                 ����������� ������ �� ����. ���� Location=MULTI_BASE. �� �������
//                 �� ���������� ����� �������������� � ������ ���� ������.
//                 ���� ������ ��� ����������� � � ��� ���� ���� �����������,
//                 �� ��������, ���������� ACTION=MULTI_DEL, ����� ������� �� ����.
//                 ���� Action=MULTI_DSC, �� � ������������� � ������� ���� ��������
//                 ���������� �������� �� �������� � Description.
//                 ��������, ���������� Action=MULTI_NO, �� ��������� �������
//                 � ���������.
//                 ��� ���������� ���������� � ����������� ������� �������:
//         BaseMultiMediaItemAdd, BaseMultiMediaItemDel, BaseMultiMediaItemNo,
//         BaseGetMultiMediaItem

//--------- ����� ������� ��������� ������ ��� ����� -----------------
//          ������ ��������������� ������������� ����� ������� � ��������
//          ��� ����� ���� ������� BaseInitObject
	unsigned int   FlagSem;        // ������ ������������� ���� �������������:
														//  BASE_OLD_FORMAT - ������ �������������
														//    ������������ � ������� �����-
														//    ��� � pSem ���� �������� mSem ����
														//  BASE_NEW_FORMAT - ������ ��� ���� �-�
														//    ������� ����������� ���������� �� ������������
	unsigned int   FlagSv;         // ������ ������������� ���� ������:
														//  BASE_OLD_FORMAT - ����� 2. ����� �������� � ��������
														//      ������������� ������
														//  BASE_NEW_FORMAT - ����� 1: ����� �������� � ���� ������
														//                (������ ���������� �����������)
														//  BASE_OLD_FORMAT_DYN - ����� 3. ������ ������� ����������
														//       �� ������������. ����� �������� � ����� �������
	unsigned int   FlagPr;         // ������ ������������� ���� ����������:
														//  BASE_OLD_FORMAT - ����� 2. ���������� �������� � ��������
														//    �������������  ������
														//  BASE_NEW_FORMAT - ����� 1: ���������� �������� � ���� ������
														//                (������ ���������� �����������)
														//  BASE_OLD_FORMAT_DYN - ����� 3. ������ ������� ����������
														//       �� ������������. ���������� �������� � ����� �������
unsigned int  FlagSquare;     // ������ ������������� ���� ���������:
														//  BASE_OLD_FORMAT - �������� �������� � ��������
														//   ������������� ���� �������� mSquare ����
														//  BASE_NEW_FORMAT - ������ ��� ���� ���������
														//   ������� ���������� �� ������������
	unsigned int   FlagMet;        // ������ ������������� ���� �������:
														//  BASE_OLD_FORMAT - ������� �������� � ��������
														//   ������������� ���� �������� mMet ����
														//  BASE_NEW_FORMAT - ������ ��� ���� �������
														//   ������� ���������� �� ������������
	unsigned int   FlagText;       // ������ ������������� ���� ������:
														//  BASE_OLD_FORMAT - ����� �������� � ��������
														//   ������������� ���� �������� mText ����
														//  BASE_NEW_FORMAT - ������ ��� ���� ������
														//   ������� ���������� �� ������������
	unsigned int   FlagVideo;      // ������ ������������� ���� �����������:
														//  ...1 - ���������� ��� ��� ���� �������� �
														//    �������� ���� �������� mVideo ���� (BASE_OLD_FORMAT)
														//  ...0 - ������ ��� ���� �����������
														//   ������� ���������� �� ������������ (BASE_NEW_FORMAT)
														//  ..1. - ���� �������� ��� ���������� ������ � ������������
														//         (BASE_NEW_FORMAT | OBJ_VIDEO_ALL
              //          ��� BASE_OLF_FORMAT | OBJ_VIDEO_ALL)
//--------- ������� ����� ��� ����� �������  -----------------
//          ������ ���� ������ ����� ������� ������ ���
//          ������ BASE_OLD_FORMAT
//          ��� ������ ������� �� ������������
	long           mSem;           // ������ � ������ ���� pSem ���
																																//  FlagSem=BASE_OLD_FORMAT
	long           mSv;            // ������ � ������ ������� Sv ��� ����� 2
	long           mPr;            // ������ � ������ ������� Pr ��� ����� 2
	long           mSquare;        // ������ � ������ ���� pSquare
																																// ��� FlagSquare=BASE_OLD_FORMAT
	long           mMet;           // ������ � ������ ���� pMet
																																// ��� FlagMet=BASE_OLD_FORMAT
	long           mText;          // ������ � ������ ���� pText
																																// ��� FlagText=BASE_OLD_FORMAT
	long           mVideo;         // ������ � ������ ���� pVideo
																																// ��� FlagVideo=...1
//----------------- �������������� �������� ------------------------
//   �������� ��� ������
//   ������ ���� ������ ��� ������
	long           qSem;           // ���������� �������������
																																//  (���� ������ 0)
	long           qSv;            // ���������� ������
	long           qPr;            // ���������� ����������
	long           qSquare;    	   // ���������� ���������
																																//  (��������� �� 4 �����)
	long           qMet;           // ���������� ����� (���������) � �������
	long           qText;          // ��� ������ ������ ����� sText
	long           qVideo;         // ���������� ��������� � ���� �����������
//---------- ������� � ������ ������ ������� (����������� ��� ������) --------
//           ��� ������ �� ������������
	long           sSem;           // ��������� (� ������ ������� �����)
	long           sSv;            // ���� ������
	long           sPr;            // ���� ����������
	long           sSquare;        // ���� ���������. ������ ������ 4-� ������
	long           sMet;           // ���� �������
	long           sText;          // ������ � ������ ���������� ��������
	long           sVideo;         // ������ � ������ ���� �����������
//-------------------------------------------------------------------------
	int            Error[3];       // ����������� ��� ������
																																// (��.������� BaseCheckObject)
//------------------------------------------------------------------------
	BASE_INT      Code[10];        // ��� �������
	unsigned int  FlagReadWrite;   // ���� ������/������ �������:
													//  0 - ������� ���
													//  1 - ������ ��������. ���������������
													//      ����� ������ ������� �� ����
													//  2 - ������ ������� � ����.
													// ��������������� ����� ������ ������� � ����
													// ������������ � 0 ��� ���������� �������
													//  BaseInitObject, BaseCloseObject
} GBASE_OBJECT;

//= ��������� ���������� ����� �����/���������� (��� ������� BASE_NEW_FORMAT) ===
typedef struct
{
	BASE_INT      *pBack;    // ��������� �� ���������� ����� (� ������ NULL)
	BASE_INT      *pForward; // ��������� �� ��������� ����� (� ��������� NULL)
	unsigned long  Size;     // ������ �����/���������� � ������ �� 2 �����
	unsigned long  Key;      // ���� ����� (0 - 2**31)
																										// (���� 0, �� � ������ � ���� ������
																										// �����/���������� �� ���������)
	BASE_INT      Code[10];  // ��� ����������/������������ �������
	unsigned long  Number;   // ����� ����������/������������ �������
	unsigned long  Point;    // ����� ����� � ������� ��� ����������
	int            Scale;  // ���������� �����
	BASE_INT      Sem;       // ������ ���� ������������� � ������ �� 2 �����
																										// (��� 0, ���� ������������� ���)
																										//  ����� (BASE_INT *)&Sem - ������ ���� ���������
																										//  �����/����������
} BASE_SVPR;

//======= ��������� ���������� ����� �����/���������� ��� �������� ==========
//        BASE_OLD_FORMAT ��� BASE_OLD_FORMAT_DYN
typedef struct
{
	unsigned long Size;      // ������ �����/���������� � ������ �� 2 �����
	unsigned long Key;       // ���� ����� (0 - 2**31)
																										// (���� 0, �� � ������ �� ���������)
	BASE_INT      Code[10];  // ��� ���������� �������
	unsigned long  Number;   // ����� ���������� �������
	unsigned long  Point;    // ����� ����� � ������� ��� ����������
	int Scale;        // ���������� �����
	BASE_INT      Sem;       // ������ ���� ������������� � ������ �� 2 �����
																										// (��� 0, ���� ������������� ���)
																										//  ����� (BASE_INT *)&Sem - ������ ���� ���������
																										//  �����/����������
} BASE_SVPR_OLD;

//======= ��������� ��������� ���������� ����������� �������������� =====
typedef struct
{
// .... �������� ��� ������ ��������������;
// .... ������������ ��� ���������� ��� ��������� ��������������
	BASE_INT Code[10];           // ��� ��������������
	int      Type;               // ��� ��������������
	unsigned int  FlagValue;     // ���� �������� ������� BaseReadFeature
                              // (��������� ��������: VALUE_SEM0 - VALUE_SEM3)
	int qPoints;                 // ���������� ����� ��������
	void *AddrPoints;            // ��������� �� ������ ����� �������� �-��

// .... �������� ��� ������ ��������������;
	BASE_INT *AddrF;             // ��������� �� ������ ��������������
	void *AddrValue;             // ��������� �� ������ �������� �-��
	unsigned long Numb;          // ���������� ����� �������������� �� ���� ���� ���������
	unsigned long NumberCode;    // ���������� ����� �������������� ����� �������������,
                              //  ����������� �� ���������� �������
	int SizeValue;               // ����� �������� �������������� � ������

// ....������������ ������ ��� ���������� ��� ��������� ��������������
 int CountItemsMet;           // ���������� ������������ ����� �������� (1-255);
 int SizeItemMet;             // ������ ������������ ����� �������� (1-255);
} BASE_FEATURE;
//==========================================================================
typedef struct
{
 BASE_INT Code[10];    // ��� ������ �������� ��������/�������
 int FlagCode;         // ��� ������� �� ������ �� ���� �������:
                       //  OPEN_TREE - �� ����������� ����
                       //  OPEN_CODE - ������ ������� ��������� ������� ����
 unsigned long Number; // ����� ������� (���� �������� ������ ���� ������. � ����
                       //  ������ Code ��������� ������ ��� �������) ��� 0, ����
                       //  �������� ������ ��������
 char TextMKO[1000];   // ����� ������� �� ����� ��� ������ ������
 COLORREF ColorContur; // ���� ����������� ������� �������
 COLORREF ColorSquare; // ���� ������� ���������� �������
 int TypePen;          // ��� ����� �������
 int WidthPen;         // ������� ����� �������
 int TypeBrush;        // ��� ������� ���������� �������
 int NumberLayer;      // ����� �������� (����)
 int TypeXorCopyLine;  // ��������� �� ������ �������� �����
 int TypeXorCopySq;    // ��������� �� ������ �������� �������
} GBASE_MULTI_READ;

//=============== ��������� �������� ������� �� ����� �������� ==========
typedef struct
{
 char Label[4];                   // ��������� ����� ��������������� �������
 char MultiFilterName[256];       // ������������� �������� ������� (�� 250 ��������)
 char MultiFilterDescription[256];// �������� �������� ������� (�� 256 ��������)
 int CountQuerys;                 // ���������� �������� � ������� ������� (��� 0)
 GBASE_MULTI_READ *Querys;        // ��������� �� ������ �������� (��� NULL)
} GBASE_MULTI_MKO;

//=============== ��������������� ���� ��� ������������ �������� =============
// CountItemsMet=2 SizeItemMet=2 TypeItemMet=BASE_MET_INTEGER
typedef struct
{
	BASE_INT x;        // ���������� X
	BASE_INT y;        // ���������� Y
} MET_INT_2;

// CountItemsMet=3 SizeItemMet=2 TypeItemMet=BASE_MET_INTEGER
typedef struct
{
	BASE_INT x;        // ���������� X
	BASE_INT y;        // ���������� Y
	BASE_INT h;        // ������
} MET_INT_3;

// CountItemsMet=2 SizeItemMet=4 TypeItemMet=BASE_MET_INTEGER
typedef struct
{
	int x;            // ���������� X
	int y;            // ���������� Y
} MET_LONG_2;

// CountItemsMet=3 SizeItemMet=4 TypeItemMet=BASE_MET_INTEGER
typedef struct
{
	long x;            // ���������� X
	long y;            // ���������� Y
	long h;            // ������
} MET_LONG_3;

// CountItemsMet=2 SizeItemMet=4 TypeItemMet=BASE_MET_FLOAT
typedef struct
{
	float x;           // ���������� X
	float y;           // ���������� Y
} MET_FLOAT_2;

// CountItemsMet=3 SizeItemMet=4 TypeItemMet=BASE_MET_FLOAT
typedef struct
{
	float x;           // ���������� X
	float y;           // ���������� Y
	float h;           // ������
} MET_FLOAT_3;

// CountItemsMet=2 SizeItemMet=8 TypeItemMet=BASE_MET_FLOAT
typedef struct
{
	double x;          // ���������� X
	double y;          // ���������� Y
} MET_DOUBLE_2;

// CountItemsMet=3 SizeItemMet=8 TypeItemMet=BASE_MET_FLOAT
typedef struct
{
	double x;           // ���������� X
	double y;           // ���������� Y
	double h;           // ������
} MET_DOUBLE_3;

//----------- ������ �����
typedef struct
{
 BASE_INT Code[10];      // ��� ������� ��� ������ ��������
 int TypeCode;           // ��� ���������� ����:
                         //  OPEN_TREE - ������ ��������
                         //  OPEN_CODE - ������ ������� ���������� ����
 unsigned long Number;   // ����� �������. ������ ��� ������ ������
                         //  ������� ������� ���� Code (TypeCode=OPEN_CODE)
} BASE_LIST_CODE;
//===== ���� ���������� �������� ����� ������ � ������� ��������� ==========
typedef struct
{
	char Label[8];            // ����� ����� ���������� ����� ������
    char OpenReg[4];          // ����� �������� ����
	TREE *base;               // ��������� �� ������� ������ ���� ����
    char PassWord[44];        // ������
	int  FlagOpen;            // ���� �������� ����:
																											//  1 - ������ (R)
																											//  2 - ���������� (U)
																											//  4 - �������� (C)
	int BaseFormat;           // ������ ���� ������:
																											//  BASE_FORMAT_2 ��� BASE_FORMAT_3
	int CountItemsMet;        // ���������� ������������ �������� �������
																											//  (�����������) 1 - 255
	int SizeItemMet;          // ������ � ������ ������������ �������� �������
																											//   1 - 255
	int TypeItemMet;          // ��� ������������ �������� �������:
																											//  BASE_MET_INTEGER - �����
																											//  BASE_MET_FLOAT   - ������������
																											//  BASE_MET_LOGICAL - ����������
	float UnitMet;            // ������� ��������� ������� (���������� �
																											//  ����� ����������)
	unsigned long Read;       // ���������� �������� ������ �� �����
	unsigned long Write;      // ���������� �������� ������ �� �����
	unsigned long Delete;     // ���������� �������� �������� �� �����
	char FileName[256];   // ������ ��� ����� ���� ������
} GBASE;
//================ ��������� ������� �� ������ =================
typedef  struct
{
//------ ���������������� �����, ������� �� ������ ��������� ---
//       � ������� ������� BaseInitQuery
						long          Key;               // ������� ������� � �������
						int           Ident;             // ����� ������� (����� �����)
//---------- ��������� ����� ------------------------------------
//  �� ��� ������������� !!!
						int                 Level;       // ������� ����� ���������
																																							//  �������
						int                 Current;     // ������� ������� "o" ����-
																																							//  ���� �������
						unsigned long Num;               // ����� �������� �������                                       //  ���� ������� �������
						BASE_INT           Code[10];     // ��� �������� �������
						int      Type;                   // ��� �������� �������:
																																							//  OPEN_CODE - ������ �������
																																							//    � ������� ���������
																																							//  OPEN_CODE_SELECT - ��-
																																							//    �������� ������ �����-
																																							//    ��� ��������� ����
																																							//  OPEN_CODE - ������ �������
																																							//    �������� ������ �����-
																																							//    ���� ������� ����
		int                FormatFlag;       // 0 - Old Format
																																							// 1 - New Format
		int                r1;               // ������
		int                r2;               // ������
		int            FlagKV;               // ���� ��� ������ �� ���������
		int            NumberKV;             // ������� ����� ��������
		GBASE *BaseKV;                       // ��������� �� ������� ����
																																							// �� ������� �������� ���
																																							// ������ �� ������ ���������
		char *NameKV;                        // ��������� �� ��� ����������
																																							// ����� ������� ����
} GBASE_QUERY;
//=============== ��������� ������ ����� � ������� �������� =========
typedef struct
{
 BASE_INT Code[10];
 unsigned long Number;
} GBASE_LIST_OBJECTS;
//=============== ��������� ������� �� ������� ������ ================
typedef struct
{
//------------- ��� �������������
 int Key;                  // ������� ������� � ��������
 int Number;               // ����� �������
 int Status;               // ������ �������:
                           //  0 - ������
                           //  1 - ���������������
                           //  2 - ������
//------------- ��������� �����
 GBASE *Base;              // ��������� �� ���� ������
 int CountQuerys;          // ���������� ��������
 GBASE_MULTI_READ *Querys; // ��������� �� ������ ��������
 BASE_INT MKO_OBJ[500];    // ������� ����������������� ������ �� ����� ��������
 BASE_INT *MKO;
 int CurrentQuery;         // ����� �������� �������
 GBASE_QUERY Query;        // ������� ������
 int FlagCode;             // ��� ����: OPEN_TREE ��� OPEN_CODE
 int FlagQuery;            // ���� �������� �������:
                           //  1 - ������
                           //  0 - ���
//---- ��� ������ �� ��������������� �������
 int MaxCountObjects;      // ������������ ������ ������ ��������
 int CurrentList;          // ������ ������ �������� ������
 int *AdrList;             // ������ ������� �������
 int CountReadObjects;            // ���������� ��� ����������� ��������
 GBASE_LIST_OBJECTS *ListObjects; // ������ ����� � ������� ����������� ��������
} GBASE_MULTI_QUERY;
//============= ��������� ������� �� ������ ������/���������� ===========
//  �� ��� ������������� !!!
typedef struct
{
	unsigned long Q;            // ���������� ���������� ������
	BASE_SVPR *Adr;        // ����� ������� �����
	unsigned long Num;          // ���������� ����� ������� �����
	unsigned long NS;           // ����� ����� � ���
} BASE_ZAP_SP;

//================ ��������� ������� �� ������ ������������� =============
//  �� ��� ������������� !!!
typedef struct
{
	BASE_INT a[26];
	BASE_INT *pComplex;   // ����� ������ ������� ��������������
	void *AdrFeature;     // ��������� �� ���� �������������
	unsigned long Numb;       // ���������� ����� �-��, ����������� � �������
	unsigned long NumberCode; // ���������� ����� �������������� ����� �������������,
																											//  ����������� �� ���������� �������
	int Pr_otk3;              // ������� �������� �������; 1-������;0-���
	FEATURE_CODE *CodeXar;    // ����� �������������� �-�� ������� ������
} SEM_QUERY;




HINSTANCE Base01LoadFun1(
 int *err,         // ��� ����������:
                   // BERR_OK - ������ ���� ������� ���������
                   // BERR_NOINF - ���� �� ���� ������� �� �������
 GBASE_FUN01 *Fun  // ������� ������ ������ �������. ���� ��� = 1,
                   //  ������� �������, ���� = 0, �� �� �������
                   // ���� Fun==NULL, �� ������� ������ �� �����������
);

// ������� ���������� Handle ���������� ��� NULL � ������ �� ����������

typedef int (BASEEXPORTFUNC *BaseCodeStr)(short int *Code,char* s);
typedef GBASE *(BASEEXPORTFUNC *BaseOpen)(int *RetCode,char* FileName, char *Function,
									  char *Password,char *BaseName);
typedef int (BASEEXPORTFUNC *BaseClose)(GBASE *base);


typedef char * (BASEEXPORTFUNC *BaseOpenTextError)(int err,char *r);
typedef int (BASEEXPORTFUNC *BaseSetFormat)(int BaseFormat);

typedef int (BASEEXPORTFUNC *BaseSetMetDescriptor)(GBASE *Base,int Flag,int CountItemsMet,
	int SizeItemMet,int TypeItemMet,float UnitMet);
typedef int (BASEEXPORTFUNC *BaseClose)(GBASE *base);
typedef int (BASEEXPORTFUNC *BasePackMode)(GBASE *base,int Mode);
typedef int (BASEEXPORTFUNC *BaseReadObject)(GBASE *base,GBASE_QUERY *Query,
	BASE_INT *Select,int Fun,int Read,GBASE_OBJECT *Object,BASE_INT *Code,unsigned long Number);
typedef int (BASEEXPORTFUNC *BaseReadNumbers)(GBASE *base,BASE_INT *CodeObj,
	unsigned long *num_min,unsigned long *num_max);
typedef int (BASEEXPORTFUNC *BaseSetupQuery)(GBASE *base,GBASE_QUERY *Query,
	BASE_INT *Select,int reg,BASE_INT *code_zap,BASE_INT *code,unsigned long numer);
typedef void (BASEEXPORTFUNC *BaseCloseObject)(GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseReadNameClass)(GBASE *base,char *name);
typedef int (BASEEXPORTFUNC *BaseReadName)(GBASE *base,char *name);
typedef int (BASEEXPORTFUNC *BaseReadListkv)(GBASE *base,BASE_LISTKV *List);
typedef int (BASEEXPORTFUNC *BaseReadPassword)(GBASE *base,char *PassWord,
	int MaxCount,int *n);
typedef int (BASEEXPORTFUNC *BaseReadClassInfo)(GBASE *Class,int Fun,
	BASE_INT *Code,char *Name,BASE_INT *Descriptor);
typedef void (BASEEXPORTFUNC *BaseInitQuery)(GBASE_QUERY *Query,
	long Key,int Ident);
typedef int (BASEEXPORTFUNC *BaseInitObject)(GBASE_OBJECT *Object,
	BASE_INT *sem,long mSem,void *Sv,long mSv,void *Pr,long mPr,
	void *Sq,long mSq,void *Met,long mMet,char *Text,long mText,
	VIDEO_HEADER *Video,long mVideo);
typedef int (BASEEXPORTFUNC *BaseGetFreeNum)(GBASE *base,BASE_INT *kod,
	long *num);
typedef int (BASEEXPORTFUNC *BaseObjectCount)(GBASE *base,BASE_INT *Code,
	int reg,long *Count);
typedef int (BASEEXPORTFUNC *BaseInitMultiQuery)(GBASE_MULTI_QUERY *Query,
	long Key,int Number);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectOpen)(GBASE *gbase,
	GBASE_MULTI_QUERY *zap,GBASE_MULTI_MKO *Filter,
	int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectCont)(GBASE_MULTI_QUERY *zap,
	int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectRetry)(GBASE_MULTI_QUERY *zap,
	int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectRestore)(GBASE_MULTI_QUERY *zap);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectClose)(GBASE_MULTI_QUERY *zap);
typedef int (BASEEXPORTFUNC *BaseWriteObject)(GBASE *base,GBASE_OBJECT *Object,
	int Fun);
typedef int (BASEEXPORTFUNC *BaseDeleteObject)(GBASE *base,BASE_INT *code,
	unsigned long num,int reg);
typedef int (BASEEXPORTFUNC *BaseWriteNameClass)(GBASE *base,char *name);
typedef int (BASEEXPORTFUNC *BaseWriteName)(GBASE *base,char *name);
typedef int (BASEEXPORTFUNC *BaseWriteListkv)(GBASE *base,int reg,BASE_LISTKV *List);
typedef long (BASEEXPORTFUNC *BaseCheckPoint)(GBASE *base,int *RetCode);
typedef int (BASEEXPORTFUNC *BaseReadSvPr)(BASE_ZAP_SP *Query,
	GBASE_OBJECT *Object,int regsp,int reg1,BASE_INT *Select,
	unsigned long *Num,void * *pSP);
typedef int (BASEEXPORTFUNC *BaseGetAdrSvPrForNumber)(int Flag,
	GBASE_OBJECT *Object,unsigned long Number,BASE_SVPR_OLD **Adr);
typedef int (BASEEXPORTFUNC *BaseDeleteSvPr)(GBASE_OBJECT *Object,int reg,
	long nsp,void *adr);
typedef int (BASEEXPORTFUNC *BaseAddSvPr)(GBASE_OBJECT *Object,
	int reg,long nsp,void *adr,BASE_SVPR_OLD *pSP,void  * *pSPR,
	int CountItemsMet,int SizeItemMet);
typedef BASE_INT * (BASEEXPORTFUNC *BaseGetAdrSemSP)(void *AdrSP,int Flag);
typedef int (BASEEXPORTFUNC *BaseTransMKO)(char *Source,BASE_INT *MKO,
	int LengthMKO,int *ErrCode,int *ErrorSymbolNumber);
typedef int (BASEEXPORTFUNC *BaseNumbersCharToInt)(char *StrChar,
	BASE_INT *IntArray,int QNumbers,int QDigitals);
typedef int (BASEEXPORTFUNC *BaseDateDecode)(unsigned long abs_day,
	int *day,int *month,int *year);
typedef int (BASEEXPORTFUNC *BaseDateEncode)(	int day,int month,int year,
 unsigned long abs_day);
typedef double (BASEEXPORTFUNC *BaseObjectSquareAll)(int SizeItem,
 int TypeItem, int qPoints, void *Points,	double *s);
typedef int (BASEEXPORTFUNC *BaseCopyObject)(GBASE_OBJECT *ObjOut,
	GBASE_OBJECT *ObjIn,int Fun);
typedef int (BASEEXPORTFUNC *BaseCompCode)(BASE_INT *kod1,BASE_INT *kod2);
typedef int (BASEEXPORTFUNC *BaseSemCount)(BASE_INT *pSem,BASE_INT *kod_x,
	int reg,long *Count);
typedef int (BASEEXPORTFUNC *BaseReadFeature)(SEM_QUERY *Query,int Flag,
	int Reg,void *Adr,unsigned long NumberSvPr,FEATURE_CODE *CodeXar,
	BASE_XAR_VALUE *Value,BASE_FEATURE *Feature,int *Error);
typedef int (BASEEXPORTFUNC *BaseReadFeatureComp)(SEM_QUERY *Query,int Flag,
	int Reg,void *Adr,unsigned long NumberSvPr,FEATURE_CODE *CodeXar,
	int CountCodes,BASE_XAR_VALUE *Value,BASE_FEATURE *Feature,int *Error);
typedef int (BASEEXPORTFUNC *BaseDeleteFeature)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeXar,int *Error);
typedef int (BASEEXPORTFUNC *BaseDeleteFeatureComp)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeXar,int CountCodes,int *Error);
typedef int (BASEEXPORTFUNC *BaseAddFeature)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeInsert,BASE_FEATURE* Feature,
 BASE_XAR_VALUE *Value,int LengthSem,int *Error);
typedef int (BASEEXPORTFUNC *BaseAddFeatureComp)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeInsert,int N_Code,
 BASE_FEATURE* Feature,BASE_XAR_VALUE *Value,int LengthSem,int *Error);
typedef int (BASEEXPORTFUNC *BaseUpdateFeature)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeXar,BASE_FEATURE* Feature,
 BASE_XAR_VALUE *Value,int LengthSem,int *Error);
typedef int (BASEEXPORTFUNC *BaseUpdateFeatureComp)(int Flag,void *Adr,
 unsigned long NumberSvPr,FEATURE_CODE *CodeXar,int N_Code,
 BASE_FEATURE* Feature,BASE_XAR_VALUE *Value,
 int LengthSem,int *Error);
typedef int (BASEEXPORTFUNC *BaseDelMetric)(GBASE_OBJECT *Object,
 int CountPoints,int StartPoint,int CountItemsMet,int SizeItemMet);
typedef int (BASEEXPORTFUNC *BaseAddMetric)(GBASE_OBJECT *Object,
 int CountPoints,int StartPoint,int CountItemsMet,int SizeItemMet);
typedef int (BASEEXPORTFUNC *BaseUpdateMetric)(GBASE_OBJECT *Object,
 int CountPoints,void *NewMet,int StartPoint,int CountItemsMet,int SizeItemMet);
typedef int (BASEEXPORTFUNC *BaseObjectConvertCoord)(GBASE_OBJECT *ObjIn,
 int TypeItemMetIn,int SizeItemMetIn,double UnitMetIn,GBASE_OBJECT *ObjOut,
 int TypeItemMetOut,int SizeItemMetOut,double UnitMetOut);
typedef int (BASEEXPORTFUNC *BaseDeleteServiceObjects)(GBASE *base,
 int CountCodes,BASE_LIST_CODE *ListCodes);
typedef int (BASEEXPORTFUNC *BaseGetFormat)(void);
typedef int (BASEEXPORTFUNC *BaseReadConnectObjects)(GBASE *base,BASE_ZAP_SP *z,
	GBASE_OBJECT *obj,char *sl,int *err_sym,int Read,long Key,BASE_INT *mko,int lmko,
	int Fun,int r,GBASE_OBJECT *obj1,void  *  *AddrSVPR,int Flag);
typedef int (BASEEXPORTFUNC *BaseReadObjectList)(GBASE *base,GBASE_QUERY *zap,
	BASE_INT *Select,int Fun,int Read,GBASE_OBJECT *obj,int num);
typedef int (BASEEXPORTFUNC *BaseReadObjectKV)(GBASE *base,GBASE_QUERY *zap,
	int Fun,int *kv,int Read,BASE_INT *Select,GBASE_OBJECT *obj);
typedef int (BASEEXPORTFUNC *BaseReadObjectLKV)(GBASE *base,GBASE_QUERY *zap,
	BASE_INT *Select,BASE_INT *kodo,int Fun,int *kv,int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectListOpen)(GBASE *gbase,
	GBASE_MULTI_QUERY *zap,GBASE_MULTI_MKO *Filter,
	int Read,GBASE_OBJECT *Object,int *NumberList);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectListCont)(GBASE_MULTI_QUERY *zap,
	int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseMultiReadObjectListRetry)(GBASE_MULTI_QUERY *zap,
	int Read,GBASE_OBJECT *Object);
typedef int (BASEEXPORTFUNC *BaseAddPrToPoint)(GBASE_OBJECT *Object,
  int reg,int nsp,void *adr1,unsigned long NumberPoint,
		BASE_SVPR_OLD *pSP,void  * *pSPR,int CountItemsMet,int SizeItemMet);
typedef int (BASEEXPORTFUNC *BaseDeletePrNumber)(GBASE *gbase,BASE_INT *Code,
	unsigned long NumberObj,long NumberPr);
typedef int (BASEEXPORTFUNC *BaseMultiFindAnyObjectCoordIF)(int TypeFind,
 double X,double Y,GBASE *base,GBASE_MULTI_MKO *Filter,
 int CountNotFindCode, GBASE_NOT_FIND_OBJECT *NotFind,
 GBASE_FIND_ANY_OBJECT *FindObject);
typedef int (BASEEXPORTFUNC *BaseFindAnyObjectCoordIF)(int TypeFind,
 double X,double Y,void *Base,int CountFindCode,BASE_INT *ListFindCode,
 BASE_INT *Select,int CountNotFindCode,GBASE_NOT_FIND_OBJECT *NotFind,
 GBASE_FIND_ANY_OBJECT *FindObject);
typedef void (BASEEXPORTFUNC *BaseSetFindMaxDistance)(double MaxDistance);
typedef double (BASEEXPORTFUNC *BaseGetFindMaxDistance)(void);
typedef int (BASEEXPORTFUNC *BaseReadClassInfoObject)(int BaseFormat,GBASE_OBJECT *Object,
	char *Name,BASE_INT *Descriptor);

extern BaseCodeStr _BaseCodeStr;
extern BaseOpen _BaseOpen;
extern BaseClose _BaseClose;
extern BaseOpenTextError _BaseOpenTextError;
extern BaseSetFormat _BaseSetFormat;
extern BaseSetMetDescriptor _BaseSetMetDescriptor;
extern BasePackMode _BasePackMode;
extern BaseReadObject _BaseReadObject;
extern BaseReadNumbers _BaseReadNumbers;
extern BaseSetupQuery _BaseSetupQuery;
extern BaseCloseObject _BaseCloseObject;
extern BaseReadNameClass _BaseReadNameClass;
extern BaseReadName _BaseReadName;
extern BaseReadListkv _BaseReadListkv;
extern BaseReadPassword _BaseReadPassword;
extern BaseReadClassInfo _BaseReadClassInfo;
extern BaseInitQuery _BaseInitQuery;
extern BaseInitObject _BaseInitObject;
extern BaseGetFreeNum _BaseGetFreeNum;
extern BaseObjectCount _BaseObjectCount;
extern BaseInitMultiQuery _BaseInitMultiQuery;
extern BaseMultiReadObjectOpen _BaseMultiReadObjectOpen;
extern BaseMultiReadObjectCont _BaseMultiReadObjectCont;
extern BaseMultiReadObjectRetry _BaseMultiReadObjectRetry;
extern BaseMultiReadObjectRestore _BaseMultiReadObjectRestore;
extern BaseMultiReadObjectClose _BaseMultiReadObjectClose;
extern BaseWriteObject _BaseWriteObject;
extern BaseDeleteObject _BaseDeleteObject;
extern BaseWriteNameClass _BaseWriteNameClass;
extern BaseWriteName _BaseWriteName;
extern BaseWriteListkv _BaseWriteListkv;
extern BaseCheckPoint _BaseCheckPoint;
extern BaseReadSvPr _BaseReadSvPr;
extern BaseGetAdrSvPrForNumber _BaseGetAdrSvPrForNumber;
extern BaseDeleteSvPr _BaseDeleteSvPr;
extern BaseAddSvPr _BaseAddSvPr;
extern BaseGetAdrSemSP _BaseGetAdrSemSP;
extern BaseCodeStr _BaseCodeStr;
extern BaseTransMKO _BaseTransMKO;
extern BaseNumbersCharToInt _BaseNumbersCharToInt;
extern BaseDateEncode _BaseDateEncode;
extern BaseDateDecode _BaseDateDecode;
extern BaseObjectSquareAll _BaseObjectSquareAll;
extern BaseCopyObject _BaseCopyObject;
extern BaseCompCode _BaseCompCode;
extern BaseSemCount _BaseSemCount;
extern BaseReadFeature _BaseReadFeature;
extern BaseReadFeatureComp _BaseReadFeatureComp;
extern BaseDeleteFeature _BaseDeleteFeature;
extern BaseDeleteFeatureComp _BaseDeleteFeatureComp;
extern BaseAddFeature _BaseAddFeature;
extern BaseAddFeatureComp _BaseAddFeatureComp;
extern BaseUpdateFeature _BaseUpdateFeature;
extern BaseUpdateFeatureComp _BaseUpdateFeatureComp;
extern BaseDelMetric _BaseDelMetric;
extern BaseAddMetric _BaseAddMetric;
extern BaseUpdateMetric _BaseUpdateMetric;
extern BaseObjectConvertCoord _BaseObjectConvertCoord;
extern BaseDeleteServiceObjects _BaseDeleteServiceObjects;
extern BaseGetFormat _BaseGetFormat;
extern BaseReadConnectObjects _BaseReadConnectObjects;
extern BaseReadObjectList _BaseReadObjectList;
extern BaseReadObjectLKV _BaseReadObjectLKV;
extern BaseReadObjectKV _BaseReadObjectKV;
extern BaseMultiReadObjectListOpen _BaseMultiReadObjectListOpen;
extern BaseMultiReadObjectListCont _BaseMultiReadObjectListCont;
extern BaseMultiReadObjectListRetry _BaseMultiReadObjectListRetry;
extern BaseAddPrToPoint _BaseAddPrToPoint;
extern BaseDeletePrNumber _BaseDeletePrNumber;
extern BaseMultiFindAnyObjectCoordIF _BaseMultiFindAnyObjectCoordIF;
extern BaseFindAnyObjectCoordIF _BaseFindAnyObjectCoordIF;
extern BaseSetFindMaxDistance _BaseSetFindMaxDistance;
extern BaseGetFindMaxDistance _BaseGetFindMaxDistance;
extern BaseReadClassInfoObject _BaseReadClassInfoObject;


#endif
