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



#ifndef SC_LISTENERCALLS_HXX
#define SC_LISTENERCALLS_HXX

#include <list>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/lang/EventObject.hpp>

namespace com { namespace sun { namespace star {
    namespace util {
        class XModifyListener;
    }
    namespace lang {
        struct EventObject;
    }
} } }


struct ScUnoListenerEntry
{
    ::com::sun::star::uno::Reference<
        ::com::sun::star::util::XModifyListener >   xListener;
    ::com::sun::star::lang::EventObject             aEvent;

    ScUnoListenerEntry( const ::com::sun::star::uno::Reference<
                            ::com::sun::star::util::XModifyListener >& rL,
                        const ::com::sun::star::lang::EventObject& rE ) :
        xListener( rL ),
        aEvent( rE )
    {}
};


/** ScUnoListenerCalls stores notifications to XModifyListener that can't be processed
    during BroadcastUno and calls them together at the end.
*/
class ScUnoListenerCalls
{
private:
    ::std::list<ScUnoListenerEntry> aEntries;

public:
                ScUnoListenerCalls();
                ~ScUnoListenerCalls();

    void        Add( const ::com::sun::star::uno::Reference<
                            ::com::sun::star::util::XModifyListener >& rListener,
                        const ::com::sun::star::lang::EventObject& rEvent );
    void        ExecuteAndClear();
};

#endif

