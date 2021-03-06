// (c) Shanghai Astronomical Observatory (SHAO), Chinese Academy of Sciences
//
// 80 Nandan Road, Shanghai 200030
// China
//
// This library is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library. If not, see <http://www.gnu.org/licenses/>.
//
// Any bugs, questions, concerns and/or suggestions please email to
// lbq@shao.ac.cn

#ifndef PARALLELTABLE_H
#define PARALLELTABLE_H

#include <casacore/tables/DataMan/DataManager.h>
#include <casacore/tables/Tables/TableDesc.h>
#include <casacore/tables/Tables/SetupNewTab.h>
#include <casacore/tables/Tables/Table.h>
#include <casacore/tables/Tables/ScaColDesc.h>
#include <casacore/tables/Tables/ScalarColumn.h>
#include <casacore/tables/Tables/TableRecord.h>
#include <casacore/tables/TaQL/ExprNode.h>
#include <casacore/casa/Arrays/ArrayIO.h>
#include <casacore/casa/Arrays/ArrayUtil.h>
#include <casacore/casa/Containers/Block.h>
#include <casacore/casa/Utilities/Assert.h>
#include <casacore/casa/Exceptions/Error.h>
#include <casacore/casa/iostream.h>
#include <casacore/tables/Tables/ArrColDesc.h>
#include <casacore/tables/Tables/ArrayColumn.h>
#include <casacore/casa/namespace.h>
#include <mpi.h>

class ParallelTable{
    public:
        ParallelTable(const string, const unsigned int, const unsigned int, const unsigned int);
        virtual ~ParallelTable();
        Table* get_table();
        virtual const unsigned int row(unsigned int) const = 0;
        const unsigned int rows() const;
        virtual void addColumn(const ColumnDesc &columnDesc)=0;
        virtual void createTable()=0;
    protected:
        void addColumnBalanced(const ColumnDesc &columnDesc);
        void addColumnUnbalanced(const ColumnDesc &columnDesc);
        void createTableBalanced(unsigned int pRows);
        void createTableUnbalanced(unsigned int pRows);
        string tablename;
        unsigned int mpi_size;
        unsigned int mpi_rank;
        unsigned int rows_total;
        unsigned int rows_per_process;
        TableDesc *td;
        Table *table;
        DataManager *stman;

};

#endif

