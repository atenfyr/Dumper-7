#pragma once
#include "ObjectArray.h"
#include "CollisionManager.h"
#include "StructManager.h"
#include "MemberManager.h"
#include "PredefinedMembers.h"


class StructWrapper
{
private:
    friend class PropertyWrapper;
    friend class FunctionWrapper;

private:
    union
    {
        const UEStruct Struct;
        const PredefinedStruct* PredefStruct;
    };

    StructInfoHandle InfoHandle;

    bool bIsUnrealStruct = false;

public:
    StructWrapper(const PredefinedStruct* const Predef);

    StructWrapper(const UEStruct Str);

public:
    UEStruct GetUnrealStruct() const;

public:
    std::string GetName() const;
    std::string GetRawName() const;
    std::string GetFullName() const;
    std::string GetPathName() const;
    StructWrapper GetSuper() const;

    /* Name, bIsUnique */
    std::pair<std::string, bool> GetUniqueName() const;
    int32 GetLastMemberEnd() const;
    int32 GetAlignment() const;
    int32 GetSize() const;
    int32 GetUnalignedSize() const;

    bool ShouldUseExplicitAlignment() const;
    bool HasReusedTrailingPadding() const;
    bool IsFinal() const;

    bool IsClass() const;
    bool IsUnion() const;
    bool IsFunction() const;

    bool IsAClassWithType(UEClass TypeClass) const;

    bool IsValid() const;
    bool IsUnrealStruct() const;

    bool IsCyclicWithPackage(int32 PackageIndex) const;

    bool HasCustomTemplateText() const;
    std::string GetCustomTemplateText() const;

    MemberManager GetMembers() const;
};
