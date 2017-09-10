#ifndef OPENRCT2_INTENT_H
#define OPENRCT2_INTENT_H

#include "../common.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include "../interface/window.h"
#ifdef __cplusplus
}
#endif // __cplusplus


#ifdef __cplusplus

#include <map>

class Intent
{
private:
    rct_windowclass _Class;
    std::map<uint32, uint32> _UInts;
    std::map<uint32, sint32> _SInts;
    std::map<uint32, utf8string> _Strings;
    std::map<uint32, uintptr_t> _Pointers;
public:
    explicit Intent(rct_windowclass windowclass);
    rct_windowclass GetWindowClass();
    void * GetPointerExtra(uint32 key);
    utf8string GetStringExtra(uint32 key);
    uint32 GetUIntExtra(uint32 key);
    sint32 GetSIntExtra(uint32 key);
    Intent * putExtra(uint32 key, uint32 value);
    Intent * putExtra(uint32 key, uintptr_t value);
    Intent * putExtra(uint32 key, sint32 value);
    Intent * putExtra(uint32 key, utf8string value);
};


extern "C" {
#endif // __cplusplus

#ifndef __cplusplus
    typedef int Intent;
#endif // !__cplusplus

    enum
    {
        INTENT_EXTRA_0,
        INTENT_EXTRA_1,

        INTENT_EXTRA_2,

        INTENT_EXTRA_3,
    };

    Intent *intent_create(rct_windowclass clss);
    void intent_release(Intent * intent);
    void intent_set_string(Intent *, uint32 key, utf8string value);
    void intent_set_pointer(Intent *, uint32 key, uintptr_t value);
    void intent_set_sint(Intent *, uint32 key, sint32 value);
    void intent_set_uint(Intent *, uint32 key, uint32 value);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OPENRCT2_INTENT_H