/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebArrayBufferView_h
#define WebArrayBufferView_h

#include "../../../Platform/chromium/public/WebCommon.h"
#include "../../../Platform/chromium/public/WebPrivatePtr.h"

#if WEBKIT_USING_V8
namespace v8 {
class Value;
template <class T> class Handle;
}
#endif

namespace WTF { class ArrayBufferView; }

namespace WebKit {

// Provides access to an ArrayBufferView.
class WebArrayBufferView {
public:
    ~WebArrayBufferView() { reset(); }
    WebArrayBufferView() { }
    WebArrayBufferView(const WebArrayBufferView& v) { assign(v); }

    WEBKIT_EXPORT void* baseAddress() const;
    WEBKIT_EXPORT unsigned byteOffset() const;
    WEBKIT_EXPORT unsigned byteLength() const;

    WEBKIT_EXPORT void assign(const WebArrayBufferView&);
    WEBKIT_EXPORT void reset();

#if WEBKIT_USING_V8
    WEBKIT_EXPORT static WebArrayBufferView* createFromV8Value(v8::Handle<v8::Value>);
#endif

#if WEBKIT_IMPLEMENTATION
    WebArrayBufferView(const WTF::PassRefPtr<WTF::ArrayBufferView>&);
    WebArrayBufferView& operator=(const WTF::PassRefPtr<WTF::ArrayBufferView>&);
    operator WTF::PassRefPtr<WTF::ArrayBufferView>() const;
#endif

private:
    WebPrivatePtr<WTF::ArrayBufferView> m_private;
};

} // namespace WebKit

#endif
