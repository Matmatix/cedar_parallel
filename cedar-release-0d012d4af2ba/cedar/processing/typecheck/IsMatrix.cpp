/*======================================================================================================================

    Copyright 2011, 2012, 2013, 2014, 2015 Institut fuer Neuroinformatik, Ruhr-Universitaet Bochum, Germany
 
    This file is part of cedar.

    cedar is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    cedar is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with cedar. If not, see <http://www.gnu.org/licenses/>.

========================================================================================================================

    Institute:   Ruhr-Universitaet Bochum
                 Institut fuer Neuroinformatik

    File:        IsMatrix.cpp

    Maintainer:  Oliver Lomp
    Email:       oliver.lomp@ini.ruhr-uni-bochum.de
    Date:        2013 09 25

    Description:

    Credits:

======================================================================================================================*/

// CEDAR CONFIGURATION
#include "cedar/configuration.h"

// CEDAR INCLUDES
#include "cedar/processing/typecheck/IsMatrix.h"
#include "cedar/auxiliaries/MatData.h"

// SYSTEM INCLUDES

//----------------------------------------------------------------------------------------------------------------------
// constructors and destructor
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// methods
//----------------------------------------------------------------------------------------------------------------------

cedar::proc::DataSlot::VALIDITY
  cedar::proc::typecheck::IsMatrix::check(cedar::proc::ConstDataSlotPtr, cedar::aux::ConstDataPtr data, std::string& info) const
{
  if (auto mat_data = boost::dynamic_pointer_cast<cedar::aux::ConstMatData>(data))
  {
    if (!mat_data->isEmpty())
    {
      return this->validityOk();
    }
  }
  info = "Expected MatData, but got something else.";
  return this->validityBad();
}
