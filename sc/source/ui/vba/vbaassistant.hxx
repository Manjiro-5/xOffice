/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


#ifndef SC_VBA_ASSISTANT_HXX
#define SC_VBA_ASSISTANT_HXX

#include <cppuhelper/implbase1.hxx>
#include <ooo/vba/XAssistant.hpp>

#include <sfx2/sfxhelp.hxx>

#include "excelvbahelper.hxx"
#include <vbahelper/vbahelperinterface.hxx>

typedef ::cppu::WeakImplHelper1< ov::XAssistant > Assistant;
typedef InheritedHelperInterfaceImpl< Assistant > ScVbaAssistantImpl_BASE;

class ScVbaAssistant : public ScVbaAssistantImpl_BASE
{
private:
    sal_Bool        m_bIsVisible;
    sal_Int32       m_nPointsLeft;
    sal_Int32       m_nPointsTop;
    rtl::OUString   m_sName;
    sal_Int32       m_nAnimation;
public:
    ScVbaAssistant( const css::uno::Reference< ov::XHelperInterface > xParent, const css::uno::Reference< css::uno::XComponentContext > xContext );
    virtual ~ScVbaAssistant();
    // XAssistant 
    virtual sal_Bool SAL_CALL getOn() throw (css::uno::RuntimeException);
    virtual void SAL_CALL setOn( sal_Bool _on ) throw (css::uno::RuntimeException);
    virtual sal_Bool SAL_CALL getVisible() throw (css::uno::RuntimeException);
    virtual void SAL_CALL setVisible( sal_Bool _visible ) throw (css::uno::RuntimeException);
    virtual ::sal_Int32 SAL_CALL getTop() throw (css::uno::RuntimeException);
    virtual void SAL_CALL setTop( ::sal_Int32 _top ) throw (css::uno::RuntimeException);
    virtual ::sal_Int32 SAL_CALL getLeft() throw (css::uno::RuntimeException);
    virtual void SAL_CALL setLeft( ::sal_Int32 _left ) throw (css::uno::RuntimeException);
    virtual ::sal_Int32 SAL_CALL getAnimation() throw (css::uno::RuntimeException);
    virtual void SAL_CALL setAnimation( ::sal_Int32 _animation ) throw (css::uno::RuntimeException);

    virtual ::rtl::OUString SAL_CALL Name(  ) throw (css::script::BasicErrorException, css::uno::RuntimeException);
	// XHelperInterface
	virtual rtl::OUString& getServiceImplName();
	virtual css::uno::Sequence<rtl::OUString> getServiceNames();
};

#endif//SC_VBA_ASSISTANT_HXX
