package edu.pjatk.unikino

import java.math.BigDecimal
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id

@Entity
abstract class Pracownik : Osoba()
{

    abstract val pensja: BigDecimal

    @Id
    @GeneratedValue
    private val id: Long? = null

}