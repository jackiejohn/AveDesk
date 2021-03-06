// DeskletSkinInfo.h: interface for the DeskletSkinInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESKLETSKININFO_H__A68139D0_EDBC_444D_A270_344358ED1264__INCLUDED_)
#define AFX_DESKLETSKININFO_H__A68139D0_EDBC_444D_A270_344358ED1264__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "helper_funcs.h"
#include "deskletskin.h"

#pragma pack(push, 1)
struct SkinInfo
{
public:
	DWORD dwSize;

	WCHAR* key;
	DWORD maxKeyLength;
	UINT num;


	WCHAR* name;
	DWORD  maxNameLength;
	WCHAR* author;
	DWORD maxAuthorLength;
	WCHAR* notes;
	DWORD maxNotesLength;
	int version;

};
#pragma pack(pop)

#pragma pack(push,1)
struct SkinInfo2 /*: public SkinInfo*/
{
public:
	DWORD dwSize;

	WCHAR* key;
	DWORD maxKeyLength;
	UINT num;


	WCHAR* name;
	DWORD  maxNameLength;
	WCHAR* author;
	DWORD maxAuthorLength;
	WCHAR* notes;
	DWORD maxNotesLength;
	int version;

	WCHAR* versionString;
	DWORD maxVersionStringLength;
};
#pragma pack(pop)

struct SkinInfoWrapper2 : public SkinInfo2
{
	SkinInfoWrapper2()
	{
		dwSize = sizeof(SkinInfo2);
		key = NULL;
		name = NULL;
		author = NULL;
		notes = NULL;
		num = 0;
		maxKeyLength = 0;
		maxNameLength = 0;
		maxAuthorLength = 0;
		maxNotesLength = 0;
		version = 0;
		versionString = NULL;
		maxVersionStringLength = 0;
		AllocateDefaultSize();
	}

	~SkinInfoWrapper2()
	{
		Clear();
	}

	void AllocateDefaultSize()
	{
		Clear();

		maxKeyLength = MAX_PATH;
		maxNameLength = MAX_PATH;
		maxAuthorLength = MAX_PATH;
		maxNotesLength = MAX_PATH;
		maxVersionStringLength = MAX_PATH;

		AllocateAssignedSize();
	}

	void Clear()
	{
		delete[] key;
		key = NULL;
		delete[] name;
		name = NULL;
		delete[] author;
		author = NULL;
		delete[] notes;
		notes = NULL;
		delete[] versionString;
		versionString = NULL;
	}

	void AllocateAssignedSize()
	{
		Clear();

		key = new WCHAR[maxKeyLength+1];
		memset(key,0,sizeof(WCHAR) * (maxKeyLength+1));

		name = new WCHAR[maxNameLength+1];
		memset(name,0,sizeof(WCHAR) * (maxNameLength+1));

		author = new WCHAR[maxAuthorLength+1];
		memset(author,0,sizeof(WCHAR) * (maxAuthorLength+1));

		notes = new WCHAR[maxNotesLength+1];
		memset(notes,0,sizeof(WCHAR) * (maxNotesLength+1));

		versionString = new WCHAR[maxVersionStringLength+1];
		memset(versionString,0,sizeof(WCHAR) * (maxVersionStringLength+1));
	}

	SkinInfoWrapper2* Clone()
	{
		SkinInfoWrapper2* newWrapper = new SkinInfoWrapper2;
		newWrapper->dwSize = dwSize;

		newWrapper->key = NULL;
		newWrapper->maxKeyLength = maxKeyLength;
		newWrapper->num = num;

		newWrapper->name = NULL;
		newWrapper->maxNameLength = maxNameLength;
		newWrapper->author = NULL;
		newWrapper->maxAuthorLength = maxAuthorLength;
		newWrapper->notes = NULL;
		newWrapper->maxNotesLength = maxNotesLength;
		newWrapper->version = version;
		newWrapper->versionString = NULL;
		newWrapper->maxVersionStringLength = maxVersionStringLength;

		newWrapper->AllocateAssignedSize();

		if(newWrapper->key != NULL && key != NULL)
			wcscpy(newWrapper->key,key);

		if(newWrapper->name != NULL && name != NULL)
			wcscpy(newWrapper->name,name);

		if(newWrapper->author != NULL && author != NULL)
			wcscpy(newWrapper->author,author);

		if(newWrapper->notes != NULL && notes != NULL)
			wcscpy(newWrapper->notes,notes);

		if(newWrapper->versionString != NULL && versionString != NULL)
			wcscpy(newWrapper->versionString,versionString);

		return newWrapper;
	}
};

struct SkinInfoWrapper : public SkinInfo
{
	SkinInfoWrapper()
	{
		dwSize = sizeof(SkinInfo);
		key = NULL;
		name = NULL;
		author = NULL;
		notes = NULL;
		num = 0;
		maxKeyLength = 0;
		maxNameLength = 0;
		maxAuthorLength = 0;
		maxNotesLength = 0;
		version = 0;
		AllocateDefaultSize();
	}

	~SkinInfoWrapper()
	{
		Clear();
	}

	void AllocateDefaultSize()
	{
		Clear();

		maxKeyLength = MAX_PATH;
		maxNameLength = MAX_PATH;
		maxAuthorLength = MAX_PATH;
		maxNotesLength = MAX_PATH;

		AllocateAssignedSize();
	}

	void Clear()
	{
		delete[] key;
		key = NULL;
		delete[] name;
		name = NULL;
		delete[] author;
		author = NULL;
		delete[] notes;
		notes = NULL;
	}

	void AllocateAssignedSize()
	{
		Clear();

		key = new WCHAR[maxKeyLength+1];
		memset(key,0,sizeof(WCHAR) * (maxKeyLength+1));

		name = new WCHAR[maxNameLength+1];
		memset(name,0,sizeof(WCHAR) * (maxNameLength+1));

		author = new WCHAR[maxAuthorLength+1];
		memset(author,0,sizeof(WCHAR) * (maxAuthorLength+1));

		notes = new WCHAR[maxNotesLength+1];
		memset(notes,0,sizeof(WCHAR) * (maxNotesLength+1));
	}

	SkinInfoWrapper* Clone()
	{
		if(sizeof(SkinInfo2) == dwSize)
		{
			SkinInfoWrapper2* thisAsWrapper2 = reinterpret_cast<SkinInfoWrapper2*>(this);
			return reinterpret_cast<SkinInfoWrapper*>(thisAsWrapper2->Clone());
		}

		SkinInfoWrapper* newWrapper = new SkinInfoWrapper;
		newWrapper->dwSize = dwSize;

		newWrapper->key = NULL;
		newWrapper->maxKeyLength = maxKeyLength;
		newWrapper->num = num;

		newWrapper->name = NULL;
		newWrapper->maxNameLength = maxNameLength;
		newWrapper->author = NULL;
		newWrapper->maxAuthorLength = maxAuthorLength;
		newWrapper->notes = NULL;
		newWrapper->maxNotesLength = maxNotesLength;
		newWrapper->version = version;

		newWrapper->AllocateAssignedSize();

		if(newWrapper->key != NULL && key != NULL)
			wcscpy(newWrapper->key,key);

		if(newWrapper->name != NULL && name != NULL)
			wcscpy(newWrapper->name,name);

		if(newWrapper->author != NULL && author != NULL)
			wcscpy(newWrapper->author,author);

		if(newWrapper->notes != NULL && notes != NULL)
			wcscpy(newWrapper->notes,notes);

		return newWrapper;
	}
};


void DeleteSkinInfoWrapper(SkinInfoWrapper* wrapper);

class DeskletSkinInfo:
	public CoElement<DeskletSkinInfo, CDeskletSkin, IDeskletSkin>
{
private:
	std::wstring m_Key;
	UINT m_Num;

	std::wstring m_Name;
	std::wstring m_Author;
	int m_Version;
	std::wstring m_Notes;

	bool m_HasVersionAsString;
	std::wstring m_VersionString;

	CComObject<CDeskletSkin> *m_Wrp;
public:
	void SetSkinInfo(const SkinInfo& wrapper);
	// only function needed for CoElementUnk:
	bool GetWrapperDisp(IDispatch **unkRet);
	
	DeskletSkinInfo();
	DeskletSkinInfo(const SkinInfo& wrapper);
	virtual ~DeskletSkinInfo();

	std::wstring GetKey()const;
	UINT GetNum()const;
	std::wstring GetName()const;
	std::wstring GetAuthor()const;
	std::wstring GetNotes()const;
	int GetVersion()const;

	bool HasVersionAsString()const;
	std::wstring GetVersionAsString()const;

	SkinInfoWrapper* GetSkinInfoWrapper()const;
	void Clear();
	bool IsAssigned()const;


};

#endif // !defined(AFX_DESKLETSKININFO_H__A68139D0_EDBC_444D_A270_344358ED1264__INCLUDED_)
