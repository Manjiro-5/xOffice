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



#ifndef SC_ACCESSIBLEFILTERMENUITEM_HXX
#define SC_ACCESSIBLEFILTERMENUITEM_HXX

#include "AccessibleContextBase.hxx"
#include "cppuhelper/implbase1.hxx"

#include <com/sun/star/accessibility/XAccessibleAction.hpp>

class ScMenuFloatingWindow;

typedef ::cppu::ImplHelper1<
    ::com::sun::star::accessibility::XAccessibleAction > ScAccessibleFilterMenuItem_BASE;

class ScAccessibleFilterMenuItem : 
    public ScAccessibleContextBase,
    public ScAccessibleFilterMenuItem_BASE
{
public:
    explicit ScAccessibleFilterMenuItem(
        const ::com::sun::star::uno::Reference<
            ::com::sun::star::accessibility::XAccessible>& rxParent, ScMenuFloatingWindow* pWin, const ::rtl::OUString& rName, size_t nMenuPos);

    virtual ~ScAccessibleFilterMenuItem();

	// XAccessibleContext

    virtual sal_Int32 SAL_CALL getAccessibleChildCount()
        throw (::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Reference< 
        ::com::sun::star::accessibility::XAccessible > SAL_CALL
    	getAccessibleChild(sal_Int32 nIndex)
            throw (::com::sun::star::uno::RuntimeException, ::com::sun::star::lang::IndexOutOfBoundsException);

	virtual ::com::sun::star::uno::Reference< 
        ::com::sun::star::accessibility::XAccessibleStateSet> SAL_CALL
    	getAccessibleStateSet()
            throw (::com::sun::star::uno::RuntimeException);

	virtual ::rtl::OUString SAL_CALL getImplementationName()
        throw (::com::sun::star::uno::RuntimeException);

    // XAccessibleAction

    virtual ::sal_Int32 SAL_CALL getAccessibleActionCount() 
        throw (::com::sun::star::uno::RuntimeException);

    virtual ::sal_Bool SAL_CALL doAccessibleAction(sal_Int32 nIndex) 
        throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);

    virtual ::rtl::OUString SAL_CALL getAccessibleActionDescription(sal_Int32 nIndex) 
        throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Reference< 
        ::com::sun::star::accessibility::XAccessibleKeyBinding > SAL_CALL 
        getAccessibleActionKeyBinding(sal_Int32 nIndex) 
            throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);

    // XInterface

	virtual ::com::sun::star::uno::Any SAL_CALL queryInterface( 
		::com::sun::star::uno::Type const & rType ) 
		    throw (::com::sun::star::uno::RuntimeException);

	virtual void SAL_CALL acquire() throw ();
	virtual void SAL_CALL release() throw ();

    // Non-UNO Methods

    void setEnabled(bool bEnabled);

protected:

	virtual Rectangle GetBoundingBoxOnScreen() const
		throw (::com::sun::star::uno::RuntimeException);

	virtual Rectangle GetBoundingBox() const
		throw (::com::sun::star::uno::RuntimeException);

private:
    bool isSelected() const;
    bool isFocused() const;
    void updateStateSet();

private:
    ::com::sun::star::uno::Reference< ::com::sun::star::accessibility::XAccessibleStateSet > mxStateSet;

    ScMenuFloatingWindow* mpWindow;
    ::rtl::OUString maName;
    size_t mnMenuPos;
    bool mbEnabled;
};

#endif
