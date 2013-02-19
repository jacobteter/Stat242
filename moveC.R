moveC <- function(origin, t){
  #passes these arguments from the BML object "origin" down to C
  # origin is the matrix, unwound as a long vector (by columns)
  # t is the number of timesteps
  stopifnot(class(origin) == c('BML', 'matrix'))
  stopifnot(class(t) == 'numeric' & t > 0)
  nrow <- attributes(origin)$dim[1]
  ncol <- attributes(origin)$dim[2]
  attributes(TestBML)$dim[1]
  .C("Rmove", origininteger(n), val = integer(n))$val
}