package medicalApplication.Model;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import medical.com.medicalApplication.model.PatientHistory;
import medical.com.medicalApplication.model.Medication;
import medical.com.medicalApplication.model.Allergey;
import medical.com.medicalApplication.model.Treatment;

public class TestPatientHistory {
	private PatientHistory jSmith;

	@Before
	public void before() {		//sets up initial class for default constructor
		this.jSmith = new PatientHistory();
	}

	@Test
	public void testAddAllergey() {		//tests the add and get functions for allergies
		Allergey newAllergy = new Allergey("Sniffles");
		List<Allergey> expectedAllergy = new ArrayList<Allergey>();
		expectedAllergy.add(newAllergy);
		jSmith.addAllergy(newAllergy);
		assertTrue(jSmith.getAlergies().equals(expectedAllergy));
	}
	
	@Test
	public void testAddTreatment() {		//tests the set and getall functions for treatments
		Treatment newTreatment = new Treatment("1/1/2020", "Knee replacement", "needs metal ball joint");
		List<Treatment> expectedTreatment = new ArrayList<Treatment>();
		expectedTreatment.add(newTreatment);
		jSmith.addTreatment(newTreatment);
		assertTrue(jSmith.getAllTreatments().equals(expectedTreatment));
	}
	
	@Test
	public void testAddMedication() {		//will test the add and get medication functions of the class
		Treatment newTreatment = new Treatment("1/1/2020", "Knee replacement", "needs metal ball joint");
		jSmith.addTreatment(newTreatment);
		
		Medication newMedication = new Medication("Cortozal", "4/21/2020", "5/13/2020", "100mg");
		List<Medication> expectedMedication = new ArrayList<Medication>();
		expectedMedication.add(newMedication);
		jSmith.addMedication(newMedication);
		assertTrue(jSmith.getAllMedications().equals(expectedMedication));
	}
}
