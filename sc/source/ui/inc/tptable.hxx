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



#ifndef SC_TPTABLE_HXX
#define SC_TPTABLE_HXX

#include <sfx2/tabdlg.hxx>
#include <vcl/fixed.hxx>
#include <vcl/lstbox.hxx>
#include <vcl/field.hxx>

//===================================================================

/** A vcl/NumericField that additionally supports empty text.
    @descr  Value 0 is set as empty text, and empty text is returned as 0. */
class EmptyNumericField : public NumericField
{
public:
    inline explicit     EmptyNumericField( Window* pParent, WinBits nWinStyle ) :
                            NumericField( pParent, nWinStyle ) {}
    inline explicit     EmptyNumericField( Window* pParent, const ResId& rResId ) :
                            NumericField( pParent, rResId ) {}

    virtual void        Modify();
    virtual void        SetValue( sal_Int64 nValue );
    virtual sal_Int64   GetValue() const;
};

//===================================================================

class ScTablePage : public SfxTabPage
{
public:
	static	SfxTabPage*	Create			( Window*		 	pParent,
										  const SfxItemSet&	rCoreSet );
	static	sal_uInt16*		GetRanges		();
	virtual	sal_Bool		FillItemSet		( SfxItemSet& rCoreSet );
	virtual	void		Reset			( const SfxItemSet& rCoreSet );
    using SfxTabPage::DeactivatePage;
	virtual int			DeactivatePage	( SfxItemSet* pSet = NULL );
    virtual void        DataChanged     ( const DataChangedEvent& rDCEvt );

private:
                    ScTablePage( Window* pParent, const SfxItemSet& rCoreSet );
    virtual         ~ScTablePage();

    void            ShowImage();

private:
    FixedLine       aFlPageDir;
	RadioButton		aBtnTopDown;
	RadioButton		aBtnLeftRight;
    FixedImage      aBmpPageDir;
    Image           aImgLeftRight;
    Image           aImgTopDown;
    Image           aImgLeftRightHC;
    Image           aImgTopDownHC;
	CheckBox		aBtnPageNo;
	NumericField	aEdPageNo;

    FixedLine       aFlPrint;
	CheckBox		aBtnHeaders;
	CheckBox		aBtnGrid;
	CheckBox		aBtnNotes;
	CheckBox		aBtnObjects;
	CheckBox		aBtnCharts;
	CheckBox		aBtnDrawings;
	CheckBox		aBtnFormulas;
	CheckBox		aBtnNullVals;

    FixedLine           aFlScale;
    FixedText           aFtScaleMode;
    ListBox             aLbScaleMode;
    FixedText           aFtScaleAll;
    MetricField         aEdScaleAll;
    FixedText           aFtScalePageWidth;
    EmptyNumericField   aEdScalePageWidth;
    FixedText           aFtScalePageHeight;
    EmptyNumericField   aEdScalePageHeight;
    FixedText           aFtScalePageNum;
    NumericField        aEdScalePageNum;

private:
	//------------------------------------
	// Handler:
    DECL_LINK( PageDirHdl,      RadioButton* );
    DECL_LINK( PageNoHdl,       CheckBox* );
    DECL_LINK( ScaleHdl,        ListBox* );
};

#endif // SC_TPTABLE_HXX
