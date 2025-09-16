/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2023 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::myNoSlipFvPatchVectorField

Description
    This boundary condition fixes the velocity to zero at walls and assumes
    the walls are stationary.

    For stationary walls with sliding vertices, e.g. engine liners, the normal
    component of the velocity is set from the wall face-flux to ensure
    continuity.

Usage
    Example of the boundary condition specification:
    \verbatim
    <patchName>
    {
        type            noSlip;
    }
    \endverbatim

See also
    Foam::fixedValueFvPatchVectorField

SourceFiles
    myNoSlipFvPatchVectorField.C

\*---------------------------------------------------------------------------*/

#ifndef myNoSlipFvPatchVectorField_H
#define myNoSlipFvPatchVectorField_H

#include "fixedValueFvPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class myNoSlipFvPatchVectorField Declaration
\*---------------------------------------------------------------------------*/

class myNoSlipFvPatchVectorField
:
    public fixedValueFvPatchVectorField
{

public:

    //- Runtime type information
    TypeName("myNoSlip");


    // Constructors

        //- Construct from patch and internal field
        myNoSlipFvPatchVectorField
        (
            const fvPatch&,
            const DimensionedField<vector, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        myNoSlipFvPatchVectorField
        (
            const fvPatch&,
            const DimensionedField<vector, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given myNoSlipFvPatchVectorField
        //  onto a new patch
        myNoSlipFvPatchVectorField
        (
            const myNoSlipFvPatchVectorField&,
            const fvPatch&,
            const DimensionedField<vector, volMesh>&,
            const fieldMapper&
        );

        //- Disallow copy without setting internal field reference
        myNoSlipFvPatchVectorField
        (
            const myNoSlipFvPatchVectorField&
        ) = delete;

        //- Copy constructor setting internal field reference
        myNoSlipFvPatchVectorField
        (
            const myNoSlipFvPatchVectorField&,
            const DimensionedField<vector, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchVectorField> clone
        (
            const DimensionedField<vector, volMesh>& iF
        ) const
        {
            return tmp<fvPatchVectorField>
            (
                new myNoSlipFvPatchVectorField(*this, iF)
            );
        }


    // Member Functions

        // Mapping functions

            //- Map the given fvPatchField onto this fvPatchField
            virtual void map(const fvPatchVectorField&, const fieldMapper&);


        // Evaluation functions

            //- Update the coefficients associated with the patch field
            virtual void updateCoeffs();


        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
