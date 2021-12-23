// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ReadOnlyBinaryStream {

#define AFTER_EXTRA
// Add Member There
public:
    size_t      readPointer{};
    bool        unk;
    std::string ownBuf, *pBuf;

public:
    LIAPI std::string const& getData() const;
    LIAPI size_t getLength() const;
    LIAPI size_t getReadPointer() const;
    LIAPI size_t getUnreadLength() const;
    LIAPI void setReadPointer(std::size_t size);

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_READONLYBINARYSTREAM
public:
    class ReadOnlyBinaryStream& operator=(class ReadOnlyBinaryStream const&) = delete;
    ReadOnlyBinaryStream(class ReadOnlyBinaryStream const&) = delete;
    ReadOnlyBinaryStream() = delete;
#endif

public:
    /*0*/ virtual ~ReadOnlyBinaryStream();
    /*1*/ virtual bool read(void*, unsigned __int64);
    /*
    inline  ~ReadOnlyBinaryStream(){
         (ReadOnlyBinaryStream::*rv)();
        *((void**)&rv) = dlsym("??1ReadOnlyBinaryStream@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI ReadOnlyBinaryStream(std::string&&);
    MCAPI ReadOnlyBinaryStream(std::string const&, bool);
    MCAPI bool canReadBool() const;
    MCAPI bool getBool();
    MCAPI unsigned char getByte();
    MCAPI double getDouble();
    MCAPI float getFloat();
    MCAPI enum StreamReadResult getReadCompleteResult() const;
    MCAPI int getSignedBigEndianInt();
    MCAPI int getSignedInt();
    MCAPI __int64 getSignedInt64();
    MCAPI short getSignedShort();
    MCAPI std::string getString();
    MCAPI bool getString(std::string&);
    MCAPI unsigned char getUnsignedChar();
    MCAPI unsigned int getUnsignedInt();
    MCAPI unsigned __int64 getUnsignedInt64();
    MCAPI unsigned short getUnsignedShort();
    MCAPI unsigned int getUnsignedVarInt();
    MCAPI unsigned __int64 getUnsignedVarInt64();
    MCAPI int getVarInt();
    MCAPI __int64 getVarInt64();

protected:

private:

};