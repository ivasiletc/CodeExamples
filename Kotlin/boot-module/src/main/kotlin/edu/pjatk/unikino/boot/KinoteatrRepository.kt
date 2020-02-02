package edu.pjatk.unikino.boot

import edu.pjatk.unikino.Kinoteatr
import org.springframework.data.repository.CrudRepository

interface KinoteatrRepository: CrudRepository<Kinoteatr, Long>