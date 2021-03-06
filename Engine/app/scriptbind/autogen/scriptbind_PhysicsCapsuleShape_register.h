/****************************************************************************
Copyright (c) 2011-2013,WebJet Business Division,CYOU

http://www.genesis-3d.com.cn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

namespace App
{ 
    static void ICall_PhysicsCapsuleShape_SetRadius(MonoObject* self, float radius );

    static float ICall_PhysicsCapsuleShape_GetRadius(MonoObject* self);

    static void ICall_PhysicsCapsuleShape_SetHeight(MonoObject* self, float height );

    static float ICall_PhysicsCapsuleShape_GetHeight(MonoObject* self);

//********************************* Register func to mono ********************************************
	void ICallReg_ScriptRuntime_PhysicsCapsuleShape( void )
    {
        static const InternalCallDetail s_cScriptBindInternalCallDetail[] = {
             { "ScriptRuntime.PhysicsCapsuleShape::ICall_PhysicsCapsuleShape_SetRadius",            (void*)&ICall_PhysicsCapsuleShape_SetRadius},
             { "ScriptRuntime.PhysicsCapsuleShape::ICall_PhysicsCapsuleShape_GetRadius",            (void*)&ICall_PhysicsCapsuleShape_GetRadius},
             { "ScriptRuntime.PhysicsCapsuleShape::ICall_PhysicsCapsuleShape_SetHeight",            (void*)&ICall_PhysicsCapsuleShape_SetHeight},
             { "ScriptRuntime.PhysicsCapsuleShape::ICall_PhysicsCapsuleShape_GetHeight",            (void*)&ICall_PhysicsCapsuleShape_GetHeight},
        };
        int size = sizeof(s_cScriptBindInternalCallDetail) / sizeof(InternalCallDetail);
        for (int ii = 0; ii < size; ++ii)
        {
                mono_add_internal_call(s_cScriptBindInternalCallDetail[ii].__pScriptFunName,
                        s_cScriptBindInternalCallDetail[ii].__pCppFunPtr);
        }
    }
} 
