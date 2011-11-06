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


#ifndef SC_VBA_NAMES_HXX
#define SC_VBA_NAMES_HXX

#include <ooo/vba/excel/XNames.hpp>
#include <ooo/vba/XCollection.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/sheet/XNamedRanges.hpp>
#include <vbahelper/vbacollectionimpl.hxx>

class ScDocument;
class ScDocShell;

typedef CollTestImplHelper< ov::excel::XNames > ScVbaNames_BASE;

class ScVbaNames : public ScVbaNames_BASE
{
	css::uno::Reference< css::frame::XModel > mxModel;
	css::uno::Reference< css::sheet::XNamedRanges > mxNames;
	
protected:
	virtual css::uno::Reference< css::frame::XModel >  getModel() { return mxModel; }

public:
	ScVbaNames( const css::uno::Reference< ov::XHelperInterface >& xParent,  const css::uno::Reference< css::uno::XComponentContext >& xContext, const css::uno::Reference< css::sheet::XNamedRanges >& xNames , const css::uno::Reference< css::frame::XModel >& xModel );
	
	ScDocument* getScDocument();
	ScDocShell* getScDocShell();

	virtual ~ScVbaNames();

	// XEnumerationAccess
	virtual css::uno::Type SAL_CALL getElementType() throw (css::uno::RuntimeException);
	virtual css::uno::Reference< css::container::XEnumeration > SAL_CALL createEnumeration() throw (css::uno::RuntimeException);

	// Methods
	virtual css::uno::Any SAL_CALL Add( const css::uno::Any& aName , 
					const css::uno::Any& aRefersTo,
					const css::uno::Any& aVisible,
					const css::uno::Any& aMacroType,
					const css::uno::Any& aShoutcutKey,
					const css::uno::Any& aCategory,
					const css::uno::Any& aNameLocal,
					const css::uno::Any& aRefersToLocal,
					const css::uno::Any& aCategoryLocal,
					const css::uno::Any& aRefersToR1C1,
					const css::uno::Any& aRefersToR1C1Local ) throw (css::uno::RuntimeException);
	
	virtual css::uno::Any createCollectionObject( const css::uno::Any& aSource );

	// ScVbaNames_BASE
	virtual rtl::OUString& getServiceImplName();
	virtual css::uno::Sequence<rtl::OUString> getServiceNames();

};
#endif /* SC_VBA_NAMES_HXX */

