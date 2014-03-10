/*
Aqsis
Copyright (C) 2001, Paul C. Gregory and the other authors and contributors
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the software's owners nor the names of its
  contributors may be used to endorse or promote products derived from this
  software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

(This is the New BSD license)
*/

/** \file
 * \brief Version information
 * \author Paul C. Gregory (pgregory@aqsis.org)
 *
 * C-compatible header, no C++ constructs please!
 */

#ifndef AQSIS_VERSION_H_INCLUDED
#define AQSIS_VERSION_H_INCLUDED


#define	AQSIS_VERSION_MAJOR ${VERSION_MAJOR}
#define	AQSIS_VERSION_MINOR ${VERSION_MINOR}
#define	AQSIS_VERSION_BUILD ${VERSION_BUILD}

#define	AQSIS_VERSION_STR   "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}${BUILDTYPE}"
#define AQSIS_VERSION_STR_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}${BUILDTYPE} (revision ${SCM_REVISION})"


#endif	/* AQSIS_VERSION_H_INCLUDED */
